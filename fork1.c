#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid2, pid3, pid4;
    printf("Soy el proceso padre, y mi PID es: %d\n", getpid());

    pid2 = fork();

    if (pid2 == 0)
    {
        if (getpid() %2 == 0)
        {
            printf("El proceso 2 es par, mi pid es :%d\n, y el de mi padre : %d\n",getpid(), getppid());
        }
        else
        {
            printf("El proceso 2 es impar, %d\n", getpid());
        }
        exit(0);
    }
    else
    {
        wait(NULL);//El padre espera al hijo

        pid3 = fork();
        if (pid3 == 0)
        {
            if (getpid() % 2 == 0)
            {
                printf("El proceso 3 es par, mi pid es :%d\n, y el de mi padre : %d\n",getpid(), getppid());
            }
            else
            {
                printf("El proceso 3 es impar, %d\n", getpid());
            }
        

        pid4 = fork();

        if (pid4 == 0 )
        {
            if (getpid() % 2 == 0)
            {
                printf(" El proceso 4 es par, mi pid es :%d\n, y el de mi padre : %d\n",getpid(), getppid());
            }
            else
            {
                printf("El proceso 4 es impar, %d\n", getpid());
            }
            exit(0);
        }
        else
        {
            wait(NULL);//De nuevo el padre(P3) espera a su hijo(P4)
            exit(0);
        }
    } 
    else
    {
        wait(NULL);//Y aqui el proceso padre P1, espera a su segundo hijo el P3
    }   
    }
    return 0;
}
//Generalmente el orden de las ejecucciones no debe cambiar, gracias al uso de wait, asegurando que los padres no continuan su ejeccución hasta la finalización de sus hijos, por lo cual el orden siempre será el mismo