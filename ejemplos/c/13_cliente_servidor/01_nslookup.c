/* http://es.tldp.org/Tutoriales/PROG-SOCKETS/prog-sockets.html */

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	int i=0;
	/* estructura para el host */
	struct hostent *host;
	/* se verifican que se haya pasado un parametro */
	if (argc!=2) {
		printf("[error] modo de uso: %s HOSTNAME\n", argv[0]);
		return EXIT_FAILURE;
	}
	/* se busca el host a partir de su nombre */
	if ((host=gethostbyname(argv[1]))==NULL) {
		printf("[error] gethostbyname()\n");
		return EXIT_FAILURE;
	}
	/* mostrar nombre verdadero del host */
	printf("Host\t%s\n",host->h_name);
	/* mostrar ip del host */
	printf("IP\t%s\n",
	       inet_ntoa(*((struct in_addr *)host->h_addr_list[0])));
	/* mostrar alias, recorrer lista de aliases (uso de CNAME en DNS) */
	printf("Alias\t");
	for (i=0; host->h_aliases[i]!=NULL; ++i)
		printf("%s ", host->h_aliases[i]);
	printf("\n");
	/* mostrat tipo de dirección */
	printf("Type\t%d\n", host->h_addrtype);
	/* mostrar largo de la direccion */
	printf("Length\t%d byte\n", host->h_length);
	/* mostrar lista de direcciones ips devueltas */
	printf("IPs\t");
	for(i=0; host->h_addr_list[i]!=NULL; ++i)
		printf("%s ",
			inet_ntoa(*((struct in_addr *)host->h_addr_list[i])));
	printf("\n");
	/* retorno programa al sistema */
	return EXIT_SUCCESS;
}
