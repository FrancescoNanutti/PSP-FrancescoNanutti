#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main()
{
    int pipe_fd[2];
    __pid_t pid;

    if (pipe(pipe_fd) == -1)
    {
     perror("Error al crear al pipe");
     return 1;
    }

    pid = fork();
    
    if (pid > 0)
    {
        close(pipe_fd[0]);//EL padre deja de leer

        char numeros[20];
        while (1)
        {
            printf("Ingresa un número. Al presionar + terminas y obtendrás las sumas de los numeros introducidos\n");
            fgets(numeros, sizeof(numeros), stdin);
             numeros[strcspn(numeros, "\n")] = '\0';//Evita el salto de linea

            write(pipe_fd[1], numeros, strlen(numeros) + 1);//Escribe en el pipe

            if (strcmp(numeros, "+") == 0) 
            break;//Termina si se escribe un +
        
        }

        close(pipe_fd[1]);//Cierra la escritura en el padre
    }
    else
    {
        close(pipe_fd[1]);///Cierra la escritura en el hijo
        char buffer[20];
        int suma = 0;

        //Lee el pipe
        while (1)
        {
            read(pipe_fd[0], buffer, sizeof(buffer));
            if (strcmp(buffer, "+")== 0)
            break;
            int num = atoi(buffer);
            printf("Número: %d\n", num);
            suma += num;///Suma los numeros
        }
        printf("La suma total es: %d\n", suma);//Muestra la suma
        close(pipe_fd[0]);//Cierra la lectura del hijo
        
    }
    return 0;
    
}