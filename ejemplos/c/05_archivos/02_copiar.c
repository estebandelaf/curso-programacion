/**
 * Programa que copia un archivo
 *
 * Compilar con:
 *  $ gcc -Wall -ansi -pedantic 02_copiar.c -o copiar
 *
 * Ejecutar con:
 *  $ ./copiar <file_in> <file_out>
 *
 * Por defecto si no se ingresan nombres de archivos se usará input.txt y
 * output.txt
 *
 * @author Esteban De La Fuente Rubio, DeLaF (esteban[at]delaf.cl)
 * @version 2014-05-24
 */

/* bibliotecas */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/* macros */
#define FILE_BUFFER_SIZE 1024

/**
 * Función que copia un archivo en otro
 * @param file_in Archivo de entrada (de donde copiar)
 * @param file_out Archivo de salida (a donde copiar)
 * @return Cantidad de bytes copiados (o -1 en caso de error)
 * @author Esteban De La Fuente Rubio, DeLaF (esteban[at]delaf.cl)
 * @version 2013-04-28
 */
int file_copy(char *file_in, char *file_out)
{
	/* variables */
	FILE *fd_in, *fd_out;
	char buffer[FILE_BUFFER_SIZE];
	int leido = 0, escrito = 0;
	/* abrir archivo de entrada */
	fd_in = fopen(file_in, "r");
	if (fd_in==NULL) return -1;
	/* abrir archivo de salida */
	fd_out = fopen(file_out, "w");
	if (fd_out==NULL) return -1;
	/* copiar archivo de entrada en el de salida */
	while (!feof(fd_in)) {
		leido += fread(buffer, sizeof(char), sizeof(buffer), fd_in);
		escrito += fwrite(buffer, sizeof(char), leido, fd_out);
	}
	/* cerrar archivos */
	if (fclose(fd_in)!=0) return -1;
	if (fclose(fd_out)!=0) return -1;
	/* retornar cantidad de bytes copiados */
	if (leido == escrito) return leido;
	else {
		errno = EIO;
		return -1;
	}
	return 0;
}

/**
 * Función principal del programa
 * @param argc Cantidad de parámetros pasados al programa + 1
 * @param argv Parámetros pasados al programa (incluyendo nombre del programa en índice 0)
 * @return Estado de retorno al sistema
 * @author Esteban De La Fuente Rubio, DeLaF (esteban[at]delaf.cl)
 * @version 2014-05-24
 */
int main (int argc, char *argv[])
{
	/* variables */
	int copiado = 0;
	/* copiar archivos */
	if (argc==3) copiado = file_copy(argv[1], argv[2]);
	else if (argc==2) copiado = file_copy(argv[1], "output.txt");
	else if (argc==1) copiado = file_copy("input.txt", "output.txt");
	else {
		errno = EINVAL;
		perror("main()");
		return EXIT_FAILURE;
	}
	/* verificar que no haya habido error en la copia y retornar al sistema */
	if (copiado==0) {
		printf("Archivo de entrada vacio\n");
		return EXIT_SUCCESS;
	}
	else if (copiado>0) {
		printf("Se copiaron %d bytes\n", copiado);
		return EXIT_SUCCESS;
	}
	else {
		perror("file_copy()");
		return EXIT_FAILURE;
	}
}
