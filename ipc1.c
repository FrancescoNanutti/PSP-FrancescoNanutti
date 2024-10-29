#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main()
{
    int pipe_fd[2];//Declaramos el pipe
    __pid_t pid;

    if (pipe(pipe_fd) == -1) //Esta linea verifica que se cree el pipe6
    {
        perror("Error al crear el pipe");
        return 1;
    }

        pid = fork();

    if (pid > 0)
    {
       close(pipe_fd[0]);//Cierra la lectura del pipe en el padre
        
        //Codigo para obtener la hora
        time_t hora;
        time(&hora);
        char * fecha = ctime(&hora); 

        write(pipe_fd[1], fecha, strlen(fecha)+ 1);//Escribe la fecha y hora en el pipe
        close(pipe_fd[1]);//Cierra la escritura en el padre
    }
    else if (pid == 0)
    {
        close(pipe_fd[1]);//Cierra la escritura en el hijo
        char fecha[26];


        read(pipe_fd[0],fecha, sizeof(fecha));
        printf("Soy el proceso hijo con pid: %d\n", getpid());
        printf("Fecha/hora: %s",fecha);
    
    close(pipe_fd[0]);
    }
    return 0;
}


