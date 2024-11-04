#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

long calcularFactorial(int num)
{
    long factorial = 1;
    for (int i = 1; i<= num; i++)
    {
        factorial *=i;
    }
    return factorial;
}

int main()
{
  int pipe1[2];//Pipe num 1 para enviar el número del padre al hijo
  int pipe2[2];//Pipe 2 para enviar el numero factorial del hijo al padre
  pid_t pid;

  pipe(pipe1);
  pipe(pipe2);

  pid = fork();

  if (pid > 0)
  {
    //Proceso P1
    close(pipe1[0]);//Cierra la lectura del pipe1
    close(pipe2[1]);//Cierra la escritura del pipe2
  
   time_t t;
   srand((unsigned) time(&t));
   int numrandom = rand() %11;
   printf("El proceso padre genera el número %d en el pipe 1\n", numrandom);

 
    write(pipe1[1], &numrandom, sizeof(numrandom));//Manda el número al proceso hijo a través de pipe1
    close(pipe1[1]);// Cierra la escritura del pipe 1 

    long factorial;
    read(pipe2[0], &factorial, sizeof(factorial));
    printf("El factorial calculado por el proceso hijo: %d! = %ld\n", numrandom, factorial);
    close(pipe2[0]);//Cierra la lectura del pipe2
  }
  else if (pid == 0)
  {
    //Proceso P2
    close(pipe1[1]);//Cierra la escritura de pipe1
    close(pipe2[0]);//Cierra la lectura del pipe2

    int num;
    read(pipe1[0], &num, sizeof(num));
    close(pipe1[0]);//Pipe1 termina de leer

    long factorial = calcularFactorial(num);

   
    write(pipe2[1], &factorial, sizeof(factorial));//Manda el resultado a traves del pipe2 
    close(pipe2[1]);//Pipe2 deja de escribir
  }
  
  return 0;

}