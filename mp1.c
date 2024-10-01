#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) 
    {
        printf("Soy el proceso hijo. Mi nombre es: Francesco Nanutti\n");
        exit(0);
    } 
    
    else 
    {
        int tiempoespera;
        waitpid(pid, &tiempoespera, 0);
        printf("Soy el proceso padre. Mi PID es: %d y el PID de mi hijo es: %d\n", getpid(), pid);
    }

    return 0;
}