#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t p2, p3;

    
    p2 = fork();
    
    
    if (p2 == 0) {
        
        pid_t p2_pid = getpid();
        pid_t p1_pid = getppid();
        
        
        printf("Soy el proceso padre. Mi PID es %d y el PID de mi padre es %d\n", p2_pid, p1_pid);
        wait(NULL);
       
        p3 = fork();
        
        
     if (p3 == 0) {
            
            pid_t p3_pid = getpid();
            pid_t p2_pid = getppid();
            
           
            printf("Soy el proceso hijo. Mi PID es %d y el PID de mi padre es %d\n", p3_pid, p2_pid);
            

        } else 
        {
            wait(NULL);
            
        }
    } else {
        
        pid_t p1_pid = getpid();
        
        printf("Soy el proceso abuelo. Mi PID es %d y el PID de mi hijo es %d\n", p1_pid, p2);
        wait(NULL);
    }

    return 0;
}