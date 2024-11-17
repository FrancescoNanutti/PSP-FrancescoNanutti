#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO1 "/tmp/FIFO1"
#define FIFO2 "/tmp/FIFO2"

int calcularFactorial (int num)
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
        int numerorandom, resultado;
        int fd_fifo1, fd_fifo2;

        fd_fifo1 = open(FIFO1, O_RDONLY);
        read(fd_fifo1, &numerorandom, sizeof(numerorandom));
        close(fd_fifo1);

        printf("FIFO12: Número para calcular factorial : %d\n",numerorandom);

        resultado = calcularFactorial(numerorandom);

        fd_fifo2 = open(PIPE02, O_WRONLY);
        write(fd_fifo2, &resultado, sizeof(resultado));
        close(fd_fifo2);

        printf("FIFO12 : Factorial calculado : %d\n", resultado);

        return 0;
    }
    
