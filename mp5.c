#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main() {
    pid_t pid1, pid2;
    
    printf("AAA \n");  
    
    pid1 = fork();
    if (pid1 == 0) { 
        
        printf("BBB \n"); 
        exit(0); 
    } 
    else 
    {
        pid2 = fork();
        if (pid2 == 0) 
        { 
            
            printf("CCC \n"); 
            exit(0); 
        } 
        else 
        {
            // El proceso padre espera a que ambos hijos terminen antes de imprimir
            waitpid(pid1, NULL, 0); 
            waitpid(pid2, NULL, 0); 
           
        }
    }
}