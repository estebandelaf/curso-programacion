#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define HEADER_SIZE 256
#define BODY_SIZE 1024
#define BUFFER_SIZE HEADER_SIZE+BODY_SIZE
#define DEFAULT_PORT 6080

void httpd (int conexion);

int main(int argc, char * argv[])
{
	struct sockaddr_in server;
	int addrlen, sock, conexion, port, processID;
	/* definir puerto a utilizar */
	port = argc==2 ? atoi(argv[1]) : DEFAULT_PORT;
	/* crear socket */
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("No se ha podido crear el socket");
		return EXIT_FAILURE;
	}
	/* inicializar estructura del servidor */
	bzero(&server, sizeof(server));
	server.sin_family = PF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
	/* enlazar el socket a la/s ip/s en que se escuchara */
	if (bind(sock, (struct sockaddr *) &server, sizeof(server))<0) {
		close(sock);
		perror("No se ha podido enlazar el socket");
		return EXIT_FAILURE;
	}
	/* inicializar la escucha de conexiones entrantes en el socket */
	if (listen(sock, 0) < 0) {
		close(sock);
		perror ("No se ha podido iniciar la escucha de conexiones entrantes");
		return EXIT_FAILURE;
	}
	/* tamaño de la estructura de la variable server */
	addrlen = sizeof(struct sockaddr_in);
	/* ignorar señal SIGCHLD enviada por los hijos (evita zombies sin
	manejarlos) */
	signal(SIGCHLD, SIG_IGN);
	/* iniciar bucle infinito */
	while (1) {
		/* espera por una conexion conexion entrante */
		conexion = accept(sock, (struct sockaddr *)&server, (socklen_t *)&addrlen);
		/* hace un fork al proceso creando un hijo */
		if ((processID = fork()) < 0) {
			close(conexion);
			perror("No se ha podido hacer fork()");
			return EXIT_FAILURE;
		}
		/* si este es el proceso padre */
		else if (processID > 0) {
			/* mostrar mensaje de nuevo hijo creado por conexion
			aceptada */
			printf(
				"Creado nuevo hijo con PID %d"
				" para la conexion desde %s\n",
				processID, inet_ntoa(server.sin_addr));
		}
		/* si este es el proceso hijo */
		else if (processID == 0) {
			/* se llama al servidor web */
			httpd(conexion);
			/* fin de la conexion */
			printf("Fin de la conexión desde la IP %s y PID %d\n",
			       inet_ntoa(server.sin_addr), getpid());
			close(conexion);
			exit(EXIT_SUCCESS);
		}
	}
	/* cerrar socket */
	close(sock);
	/* retorno al sistema */
	return EXIT_SUCCESS;
}

void httpd (int conexion)
{
	time_t now;
	char buffer[BUFFER_SIZE], header[HEADER_SIZE], body[BODY_SIZE];
	int len = read(conexion, buffer, sizeof(buffer));
	buffer[len] = '\0';
	/* generar pagina */
	time(&now);
	sprintf(body,	"<html><body><h1>httpd</h1><ul>"
			"<li>time: %s</li>"
			"<li>conexion: %d</li>"
			"<li>pid: %d</li>"
			"<li>ppid: %d</li>"
			"</ul><pre>%s</pre></body></html>",
		ctime(&now), conexion, getpid(), getppid(), buffer);
	/* generar cabecera */
	sprintf(header, "HTTP/1.1 200 OK\n"
			"Date: Wed, 14 Sep 2011 19:28:00 GMT\n"
			"Content-Type: text/html"
			"\nContent-Length: %d\n\n",
		(int)strlen(body));
	/* generar buffer a enviar */
	sprintf(buffer, "%s%s", header, body);
	/* enviar buffer al cliente */
	write(conexion, buffer, strlen(buffer));
}
