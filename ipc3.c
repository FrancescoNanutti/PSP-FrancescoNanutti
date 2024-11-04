#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main()
{
    int pipe_fd[2];
    pipe(pipe_fd);

    if (fork() > 0)
    {
        close (pipe_fd[1]);
        int numeros[2];

        //Lee los números aleatorios
        read (pipe_fd[0], numeros, sizeof(numeros));

        int numero1 = numeros[0];
        int numero2 = numeros[1];

        printf("%d + %d = %d\n", numero1, numero2, numero1 + numero2);
        printf("%d - %d = %d\n", numero1, numero2, numero1 - numero2);
        printf("%d * %d = %d\n", numero1, numero2, numero1 * numero2);
        printf("%d / %d = %d\n", numero1, numero2, numero1 / numero2);
    
        close(pipe_fd[0]);//El padre deja de leer
    }

    else
    {
        close(pipe_fd[0]);//El hijo deja de leer
        time_t tiempo;
        srand((unsigned) time(&tiempo));

        //Aqui se generan los números aleatorios 
        int numero1 = rand() %50 +1;
        int numero2 = rand() %50 +1;
        int numeros[2] = {numero1, numero2};

        write(pipe_fd[1], numeros, sizeof(numeros));//Escribe en el pipe los números aleatorios

        close(pipe_fd[1]); //Cierra la escritura en el hijo
    }
    
}