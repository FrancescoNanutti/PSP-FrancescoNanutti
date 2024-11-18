#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int tiempo = 0;

void manejar_alarma(int sig)
{
    tiempo +=5;
    printf("Tiempo trasncurrido: %d segundos\n", tiempo);
    alarm(5);
}

int main()
{
    signal(SIGALRM, manejar_alarma);
    alarm(5);

    while (1)
    {
        pause();
    }
    return 0;
}