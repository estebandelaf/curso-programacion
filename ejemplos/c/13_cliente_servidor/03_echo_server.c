/* Modo de uso:
1. Ejecutar servidor
2. Conectar desde telnet al puerto específicado o al por defecto:
     $ telnet localhost 6060
     o
     $ telnet example.com 6060
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define DEFAULT_PORT 6060

int main(int argc, char * argv[])
{
	/* declaracion de variables */
	char buffer[BUFFER_SIZE];
	struct sockaddr_in server;
	int len, addrlen, sock, conexion, port;
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
	/* iniciar bucle infinito */
	while (1) {
		/* aceptar conexion entrante */
		conexion = accept(sock, (struct sockaddr *)&server, (socklen_t *)&addrlen);
		printf("Conexión desde IP: %s\n",inet_ntoa(server.sin_addr));
		while((len=read(conexion, buffer, sizeof(buffer)))>0) {
			printf("Recibido: %s", buffer);
			write(conexion,buffer,len);
		}
		printf("Conexión terminada\n");
	}
	close(sock);
	return EXIT_SUCCESS;
}
