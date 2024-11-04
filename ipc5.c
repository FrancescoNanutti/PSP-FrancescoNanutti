#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    int pipe1[2];
    int pipe2[2];
    pid_t pid;
    
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) 
    {
        perror("Error al crear los pipes");
        return 1;
    }

    pid = fork();

    if (pid > 0)
    {
        //Proceso P1
        close(pipe1[1]);//Pipe1 deja de escribir
        close(pipe2[0]);//Pipe2 deja de leerse

        int dni;
        read (pipe1[0], &dni, sizeof(dni));
        close(pipe1[0]); //Pipe1 deja de leerse


        //Calcular letra del DNI
        char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        char letraNIF = letra[dni % 23];

        write (pipe2[1], &letraNIF, sizeof(letraNIF));//Envia la letra a través del pipe2 al hijo
        close(pipe2[1]); //Pipe2 deja de escribirse
    }

    else if(pid == 0)
    {
        //Proceso P2
        close(pipe1[0]);//Pipe 1 deja de leerse
        close(pipe2[1]); //Pipe 2 deja de escribirse

        int dni;
        printf("Introduce el número de DNI: ");
        scanf("%d", &dni);

        write(pipe1[1], &dni, sizeof(dni));//Envia el dni a través de pipe 1 al padre
        close(pipe1[1]); //Pipe1 deja de escribirse

        char letraNIF;
        read(pipe2[0], &letraNIF, sizeof(letraNIF));//Lee la letra NIF desde pipe2
        close(pipe2[0]);//Pipe 2 deja de leerse

        printf("La letra del NIF es %c\n", letraNIF);
    }
    return 0;
}