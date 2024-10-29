#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void manejar_alarma(int sig)
{
    int segundos;
    segundos++;
    printf("Tiempo trasncurrido: %d segundos\n", segundos);
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