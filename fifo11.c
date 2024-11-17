#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO1 "/tmp/FIFO1"
#define FIFO2 "/tmp/FIFO2"

int main()
{
    int numerofactorial;
    int fd_fifo1, fd_fifo2;

     mkfifo(FIFO1, 0666);
     mkfifo(PIPE02, 0666);


     time_t t;
     int numerorandom;
     srand((unsigned) time(&t));

     numerorandom=rand() % 10; 

     fd_fifo1 = open(FIFO1, O_WRONLY);//Abrimos y escribimos en el fifo1
     write(fd_fifo1, &numerorandom, sizeof(numerorandom));
     close(fd_fifo1);

     printf ("FIFO11: número generado : %d\n", numerorandom);

     fd_fifo2 = open(PIPE02, O_RDONLY);//Abrimos el fifo2 para leer el resultado
     read(fd_fifo2, &numerofactorial, sizeof(numerofactorial));
     close(fd_fifo2);

     printf("FIFO11: número factorial : %d\n", numerofactorial);

     //Elimina ambos fifos al terminar el proceso fifo11
     unlink (FIFO1);
     unlink (PIPE02);

     return 0;
}