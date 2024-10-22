#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid2,pid3,pid4;

    printf("Soy el proceso 1, mi pid es : %d, y el de mi padre es: %d\n Suma P1: %d\n", getpid(), getppid(), getpid() + getppid());
    
  
   pid2 = fork();
   if (pid2 == 0)
   {
    printf("Soy el proceso 2, mi pid es : %d, y el de mi padre es : %d\n Suma P2: %d\n", getpid(), getpid(), getpid() + getppid());
   
   pid3 = fork();
   if (pid3  == 0)
   {
    printf("Soy el proceso 3, mi pid es : %d, y el de mi padre es :%d\n Suma P3: %d\n", getpid(), getppid(), getpid() + getppid());
   
   pid4= fork();
   if (pid4 == 0)
   {
    printf("Soy el proceso 4, mi pid es : %d, y el de mi padre es : %d\n Suma P4: %d\n", getpid(), getppid(), getpid() + getppid());
    exit(0);
   }
   else
   {
    wait(NULL);//3 espera a 4
   }
   exit(0);
   }
   else
   {
    wait(NULL);//2 espera a 3
   }
   exit(0);
   }
   else
   {
    wait(NULL);//1 espera a 2
   }
   return 0;
}