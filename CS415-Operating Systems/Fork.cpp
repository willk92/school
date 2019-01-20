#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void procStatus(int level) {
   printf("L%d: PID[%d] (PPID[%d])\n", level, getpid(), getppid());
   fflush(NULL);
}

void levelFork(int *level,int maxlevel) {
  int locallevel= *level;
   while(locallevel!=maxlevel){
      int pid = fork();
      if (pid  == 0){
         (*level)++; // childs level is higher
         levelFork(level,maxlevel);
         return;
      }
     locallevel++;
     wait(NULL);
   }
}

int main() {
        int level = 0;
        int maxlevel=3;

        levelFork(&level,maxlevel);
        procStatus(level);
}