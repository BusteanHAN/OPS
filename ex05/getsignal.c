#define  POSIX_C_SOURCE  199309L //sigaction(), struct sigaction, sigemptyset()
#include <stdio.h> //  printf ,  getchar
#include <string.h>//  memset
#include <signal.h>//  sigaction ,  sigemptyset ,  struct  sigaction ,  SIGINT
#include <unistd.h>

volatile  sig_atomic_t  signalCount = 0;
void  newHandler(int  sig);
char mychar = '0';
int  main(void) {
  struct  sigaction  act , oldact;

  //  Define  SHR :
  memset (&act , '\0', sizeof(act));    //  Fill  act  with  NULLs  by  default
  act.sa_handler = newHandler;          //  Set  the  custom  SHR
  act.sa_flags = 0;                     //  No  flags,  used  with act.sa_handler
  sigemptyset (&act.sa_mask);           //  No  signal  masking  during  SHR  execution

  //  Install  SHR :
  sigaction(25 , &act , &oldact);   //  This  cannot  be  SIGKILL  or  SIGSTOP

  //  Count  Ctrl - Cs  pressed ;  continue  upon  Enter :
  printf("%d\n", getpid());
  while(1) {
    write(1, &mychar, 1);
    sleep(1);
  }
 
  sigaction(SIGINT , &oldact , NULL);
}

//  SHR  using  sa_handler:
void  newHandler(int  sig) {
  mychar += 1;
  if (mychar == ':') {mychar = '0';}
}
