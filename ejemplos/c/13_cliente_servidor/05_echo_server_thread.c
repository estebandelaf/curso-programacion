#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 256
#define DEFAULT_PORT 6060

struct thread_args {
	int conexion;
};

void *thread_main (void *args);

int main(int argc, char * argv[])
{
	struct sockaddr_in server;
	int addrlen, sock, conexion, port;
	pthread_t threadID; /* thread id de pthread_create() */
	struct thread_args *args; /* puntero a los argumentos del thread */
	/* definir puerto a utilizar */
	port = argc==2 ? atoi(argv[1]) : DEFAULT_PORT;
	/* crear socket */
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("No se ha podido crear el socket");
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
	}
	/* inicializar la escucha de conexiones entrantes en el socket */
	if (listen(sock, 0) < 0) {
		close(sock);
		perror ("No se ha podido iniciar la escucha de conexiones entrantes");
		exit(EXIT_FAILURE);
	}
	/* tamaño de la estructura de la variable server */
	addrlen = sizeof(struct sockaddr_in);
	/* iniciar bucle infinito */
	while (1) {
		/* aceptar conexion entrante */
		conexion = accept(sock, (struct sockaddr *)&server, (socklen_t *)&addrlen);
		/* crear espacio de memoria para los argumentos del cliente */
		args = malloc(sizeof(struct thread_args));
		/* colocar argumentos para la hebra */
		args->conexion = conexion;
		/* crear thread para el cliente */
		pthread_create(&threadID, NULL, thread_main, (void *)args);
		/* mostrar mensaje de nueva hebra creada por conexion aceptada
		*/
		printf("Creada nueva hebra con ID %ld"
			" para la conexion desde %s\n",
			(long int) threadID, inet_ntoa(server.sin_addr));
	}
	/* cerrar socket */
	close(sock);
	/* retorno al sistema */
	return EXIT_SUCCESS;
}

void *thread_main(void *args)
{
	char buffer[BUFFER_SIZE];
	int len, conexion;
	/* marcar la hebra como separada, se liberarán los recursos cuando
	termine la hebra (por simplicidad del programa) */
	pthread_detach(pthread_self());
	/* mientras la conexion este establecida y se reciban datos estos se
	devuelven al cliente */
	conexion = ((struct thread_args *)args)->conexion;
	while ((len=read(conexion, buffer, sizeof(buffer)))>0) {
		write(conexion, buffer, len);
	}
	/* fin de la conexión */
	printf("Fin de la hebra de ID %ld\n", pthread_self());
	close(conexion);
	/* terminar la hebra */
	return NULL;
}
