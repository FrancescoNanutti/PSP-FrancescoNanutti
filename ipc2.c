#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipe_fd[2];
    pipe(pipe_fd);

    if (fork() > 0)
    {
       close (pipe_fd[0]);
       char caracteres[20];

       while (1)
       {
        printf("Introduce un número para ser sumado, o un + para terminar el programa: ");
         scanf("%s", caracteres);
        caracteres[strcspn(caracteres, "\n")] = '\0';//Limpia el salto de línea en el buffer
        write(pipe_fd[1], caracteres, strlen(caracteres)+1);

        if (strcmp(caracteres, "+") == 0)// Termina el programa al escribir el simobolo más
        break;
        
       }
       close(pipe_fd[1]);//Termina de escribir en el padre
    }
    else
    {
      close(pipe_fd[1]);//Cierra la escritura en el hijo
      char caracteres[20];
      int suma = 0;

      //Condición de suma
      while (1)
      {
        read(pipe_fd[0], caracteres, sizeof(caracteres));
        if (strcmp(caracteres, "+") == 0)
        break;
        int num = atoi(caracteres);
        printf("\nNúmero a sumar: %d\n", num);
        suma += num;
      
      }
      printf("\nRecibido el caracter + \n");
      printf ("La suma total es: %d\n", suma);
      close (pipe_fd[0]); //Termina la lectura del hijo
      
    }

   return 0; 
}
