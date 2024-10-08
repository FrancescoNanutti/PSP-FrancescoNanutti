#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    pid_t p2,p3;

    p2 = fork();

    if (p2 == 0 )
    {
        sleep(10);
        printf("Proceso P2 despierto\n");
        
    }
    else
    {
          p3 = fork();
          if (p3 == 0)
          {
            pid_t p1_pid=getppid();
            pid_t p3_pid=getpid();


             printf("Soy el proceso P3, mi PID es %d y el PID de mi padre es %d\n",p1_pid,p3_pid);
             
          }
          else
          {
            //Proceso padre, espera a sus 2 hijos
            wait(NULL);
            wait(NULL);
          }
          
    }
    return 0;
}