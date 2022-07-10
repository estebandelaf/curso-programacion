#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct stat s;
	stat(argv[1], &s);
	printf("Fichero: %s\n", argv[1]);
	printf("ID dispositivo %ld\n", s.st_dev);
	printf("i-nodo %ld\n", s.st_ino);
	printf("permisos %d\n", s.st_mode);
	printf("enlaces %ld\n", s.st_nlink);
	printf("propietario %d\n", s.st_uid);
	printf("grupo %d\n", s.st_gid);
	printf("ID dispositivo (si es archivo especial) %ld\n", s.st_rdev);
	printf("tamaño en bytes %ld\n", s.st_size);
	printf("tamaño de bloque en FS %ld\n", s.st_blksize);
	printf("número de bloques de 512B allocated %ld\n", s.st_blocks);
	/*printf("último acceso %ld\n", s.st_atim.tv_sec);
	printf("último modificación %ld\n", s.st_mtim);
	printf("último cambio estado %ld\n", s.st_ctim);*/
	return EXIT_SUCCESS;
}
