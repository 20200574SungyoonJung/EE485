#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int i, pid;
  char *token, command[2000], *arguments[10];
  fgets(command, sizeof(command), stdin);
  command[strlen(command)-1] = 0;
  token = strtok(command, " ");
  if (token == NULL) {exit(-1);}
  arguments[0] = token;
  for (i = 1; i<10; i++) {
    token = strtok(NULL, " ");
    if (token == NULL)
      break;
    arguments[i] = token;
  }
  arguments[i] = NULL;

  pid = fork();
  if (pid != 0){
    wait(NULL);
  } else {
    execvp(arguments[0], arguments);
  }
}
