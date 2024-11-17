#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PIPE02 "/tmp/PIPE02"

int calcularFactorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    else
    {
        return num * calcularFactorial(num-1);
    }
    
}

int main()
{
    int numrandom, resultado;
    int fd;

    //Abrir el pipe y leer el número recibido por el fifo21
    fd = open(PIPE02, O_RDONLY);
    read(fd, &numrandom, sizeof(numrandom));
    close(fd);

    resultado = calcularFactorial(numrandom);

    //Abre el pipe y envia el resultado a fifo21
    fd = open(PIPE02, O_WRONLY);
    write(fd, &resultado, sizeof(resultado));
    close(fd);

    return 0;
}