#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <netdb.h>
#include <unistd.h>

#define HTTP_PORT 80
#define BUFFER_SIZE 10240

int main(int argc, char * argv[])
{
	int conection;
	char buffer[BUFFER_SIZE];
	struct sockaddr_in client;
	struct hostent *host;
	FILE *output;
	/* verificar parametros pasados */
	if (argc==1 || argc >= 4) {
		printf("[error] modo de uso: %s URL [PORT]\n", argv[0]);
		return EXIT_FAILURE;
	}
	/* iniciar datos del cliente */
	bzero(&client, sizeof(client));
	client.sin_family = AF_INET;
	client.sin_port = htons(argc==3?atoi(argv[2]):HTTP_PORT);
	host = gethostbyname(argv[1]);
	bcopy(host->h_addr_list[0], &client.sin_addr, host->h_length);
	/* crear socket y conectar */
	conection = socket(PF_INET, SOCK_STREAM, 0);
	connect(conection, (struct  sockaddr *)&client, sizeof(client));
	/* enviar cabecera HTTP y procesar respuesta */
	sprintf(buffer, "GET / HTTP/1.1\nHost: %s\nUser-Agent: C\n\n", argv[1]);
	write(conection, buffer, strlen(buffer));
	read(conection, buffer, sizeof(buffer));
	output = fopen("output.txt", "w");
	fprintf(output, "%s", buffer);
	fclose(output);
	/* retorno programa al sistema */
	return EXIT_SUCCESS;
}
