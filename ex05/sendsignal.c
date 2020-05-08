#define  POSIX_C_SOURCE  199309L //sigaction(), struct sigaction, sigemptyset()
#include <stdio.h> //  printf ,  getchar
#include <string.h>//  memset
#include <signal.h>//  sigaction ,  sigemptyset ,  struct  sigaction ,  SIGINT
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
 #include <stdlib.h>

int  main(int argc, char* argv[]) {
   
  while(1) {
    kill(strtoul(argv[1], NULL, 10), 25);
    sleep(3);
  }
}
