#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p1,p2,p3,p4,p5,p6;
    p1 = getpid();
    

    printf("Soy el proceso padre, mi pid es: %d\n",getpid());

    p2 = fork();
    if (p2 == 0)
    {
        printf("Soy el proceso 2, mi pid es: %d\n", getpid());
        pid_t pid_p2 = getpid();

        p3 = fork();
        if (p3 == 0)
        {
            printf("Soy el proceso 3, mi pid es: %d, y el de mi abuelo(P1) es: %d\n", getpid(), p1);

            p5 = fork();
            if (p5 == 0)
            {
                
                printf("Soy el proceso 5, mi pid es: %d, y el de mi abuelo(P2) es: %d\n", getpid(),pid_p2);
            }
            else
            {
                wait(NULL);//P3 espera P5
            }
            
        }
        else
        {
            p4 = fork();
            if (p4 == 0)
            {
                printf("Soy el proceso 4, mi pid es: %d, y el de mi abuelo(P1) es: %d\n", getpid(),p1);

                p6 = fork();
                if (p6 == 0)
                {
                    printf("Soy el proceso 6, mi pid es: %d, y el de mi abuelo(P2), es: %d\n", getpid(), pid_p2);
                }
                else
                {
                    wait(NULL);//P4 espera a P6
                }
                
            }
            else
            {
                wait(NULL);//P2 espera a P4
            }
            
        }
        
        
    }
    else
    {
      wait(NULL);//P1 espera a P2
    }
    return 0;
}