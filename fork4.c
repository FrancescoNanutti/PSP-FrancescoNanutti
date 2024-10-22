#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t p2,p3,p4,p5;
    int acumulador = getpid();
    printf("Soy el proceso padre, mi pid es: %d\n",getpid());

p2 = fork();
if (p2 == 0)
{
    p5 = fork();
    if (p5 == 0)
    {    
    if (getpid() % 2 == 0)
    {
        acumulador += 10; //Incrementa si el pid es par
    }
    else
    {
        acumulador -=100; //Resta 100 si el pid es impar
    }

    printf("Soy el proceso 5, mi pid es %d, y el de mi padre: %d\n Acumulación P5: %d\n", getpid(), getppid(), acumulador);
    exit(0); //Termina el proceso 5
}
else
{
    wait(NULL);//P2 espera a P5
    if (getpid() % 2 == 0)
    {
        acumulador += 10;
    }
    else
    {
        acumulador -=100;
    }
    printf("Soy el proceso 2, mi pid es %d, y el de mi padre: %d\n Acumulación P2: %d\n", getpid(), getppid(), acumulador);
    exit(0);//Termina el proceso 2
}
}
else
{
    p3 = fork();
    if ( p3 == 0)
    {
        p4 = fork();
        if (p4 == 0)
        {
            if (getpid() % 2 == 0)
            {
                acumulador +=10;
            }
            else
            {
                acumulador -=100;
            }
            printf("Soy el proceso 4, mi pid es: %d, y el de mi padre: %d\n Acumulador: %d\n", getpid(), getppid(), acumulador);
            exit(0);//Termina el proceso 4
        }
        else
        {
        wait(NULL); //P3 esoera a P4
        if (getpid() % 2 == 0)
        {
            acumulador += 10;
        }
        else
        {
            acumulador -=100;
        }
        printf("Soy el proceso 3, mi pid es: %d, el de mi padre: %d\n Acumulador: %d\n", getpid(), getppid(), acumulador);
        exit(0);//Termina el proceso 3
        }  
    }
    else
    {
        wait(NULL);
        wait(NULL);
        //P1 espera a P2 y a P3, respectivamente
        printf("Soy el proceso 1, mi pid es: %d, el de padre: %d\n Acumulador: %d\n", getpid(), getppid(), acumulador);
    }
    
}
return 0;
}