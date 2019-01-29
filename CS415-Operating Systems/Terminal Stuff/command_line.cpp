/*
William Kelley
CS415-Operating Systems
Command Line Interpreter

Sources:
https://stackoverflow.com/questions/24227723/c-cannot-initialize-variable-with-an-rvalue-of-type-void
*/

#ifdef __unix__
    #define IS_POSIX 1
    #define _BSD_SOURCE
#else
    #define IS_POSIX 0
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argv, char **argc)
{
    if (IS_POSIX == 1) {
        char buffer[500];
        FILE *output;

        // read output of a command
        output = popen("/bin/pwd", "r");
        char *pwd = fgets(buffer, sizeof(buffer), output);

        // strip '\n' on ending of a line
        pwd = strtok(pwd, "\n");

        puts("Path info by execute shell command 'pwd':");
        printf("\tWorkdir: %s\n", pwd);
        printf("\tFilepath: %s/%s\n", pwd, __FILE__);
    }
    return 0;
}