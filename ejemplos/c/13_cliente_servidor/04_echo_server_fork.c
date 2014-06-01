#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 256
#define DEFAULT_PORT 6060

int main(int argc, char * argv[])
{
	char buffer[BUFFER_SIZE];
	struct sockaddr_in server;
	int len, addrlen, sock, conexion, port, processID;
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
	manejarlos, esto por simplicidad, no necesitamos esperar por los hijos)
	*/
	signal(SIGCHLD, SIG_IGN);
	/* iniciar bucle infinito */
	while (1) {
		/* espera por una conexion conexion entrante */
		conexion = accept(sock, (struct sockaddr *)&server, (socklen_t *)&addrlen);
		/* hace un fork al proceso creando un hijo */
		/* en caso de que ocurriese un error */
		if ((processID = fork()) < 0) {
			close(conexion);
			perror("No se ha podido hacer fork()");
			return EXIT_FAILURE;
		}
		/* si este es el proceso padre */
		else if (processID > 0) {
			/* mostrar mensaje de nuevo hijo creado por conexion
			aceptada */
			printf("Creado nuevo hijo con PID %d"
				" para la conexion desde %s\n",
				processID, inet_ntoa(server.sin_addr));
		}
		/* si este es el proceso hijo */
		else if (processID == 0) {
			/* mientras la conexión esté establecida y se reciban
			datos estos se devuelven al cliente */
			while ((len=read(conexion, buffer, sizeof(buffer)))>0) {
				write(conexion, buffer, len);
			}
			/* fin de la conexion */
			printf("Fin de la conexión desde la IP %s y PID %d\n",
			       inet_ntoa(server.sin_addr), getpid());
			close(conexion);
			/* terminar hijo */
			return EXIT_SUCCESS;
		}
	}
	/* cerrar socket */
	close(sock);
	/* retorno al sistema */
	return EXIT_SUCCESS;
}
