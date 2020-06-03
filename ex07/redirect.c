#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#define ESC 0x1B 
#define INPUT 1
#define OUTPUT 0
int main(void)
{
    char outletter, inletter;
    int RtoF[2], FtoR[2];

    if (pipe(RtoF) == -1)
    {
        perror(" pipe1 ");
        exit(1);
    }

    if (pipe(FtoR) == -1)
    {
        perror(" pipe2 ");
        exit(1);
    }

    switch (fork())
    {
    case -1:
        perror(" fork ");
        exit(1);

    case 0:
        close(RtoF[INPUT]);
        close(FtoR[OUTPUT]);
        dup2(RtoF[0], 0);
        dup2(FtoR[1], 1);
        execl("/home/student/exercises/ex01/ex07/filter", "filter", (void*)NULL);
        

    default:
        close(RtoF[OUTPUT]);
        close(FtoR[INPUT]);
        
        do {
            inletter = getchar();
            write(RtoF[1], &inletter, 1);
            read(FtoR[0], &outletter, 1);
            write(1, &outletter, 1);
        }while (inletter!=ESC);

        close(RtoF[INPUT]);
        close(FtoR[OUTPUT]);
        
        wait(NULL);
        exit(0);
    }

    return 0;
}