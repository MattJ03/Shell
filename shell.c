#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100


void prompt() {
    printf("mySh");
    fflush(stdout);
}

void execute_command(char *args[]) {

    pid_t pid = fork();

    if(pid == 1) {
        perror("Forking failed\n");
    } else if(pid == 0){
        execvp(args[0], args) == -1)
      
        perror("arguement failed\n");
      
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

int main() {
    char args[MAX_CMD_LEN];
    char input[MAX_CMD_LEN];

    while(1) {
        prompt();
        if(!fgets(input, MAX_CMD_LEN, stdin)) {
            break; //at end of file EOF
        }
    
        input[strcspn(input, "\n") == 0];

         int i = 0;
         char *token = strtok(input, " ");
         args[i] = token;
         token = strtok(" ", NULL);

        
    }
}