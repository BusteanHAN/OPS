/******************************************************************************
 * File:         display.c
 * Version:      1.4
 * Date:         2018-02-20
 * Author:       M. van der Sluys, J.H.L. Onokiewicz, R.B.A. Elsinghorst, J.G. Rouland
 * Description:  OPS exercise 2: syntax check
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>
#include "displayFunctions.h"

int main(int argc, char *argv[]) {
  unsigned long int numOfTimes;
  unsigned int niceIncr;
  char printMethod;//, printChar;
  ErrCode err;
  
  err = SyntaxCheck(argc, argv);  // Check the command-line parameters
  if(err != NO_ERR) {
    DisplayError(err);        // Print an error message
  } else {
    printMethod = argv[1];
    //    numOfTimes = strtoul(argv[2], NULL, 10);  // String to unsigned long
    niceIncr =   strtoul(argv[3], NULL, 10);
    //printChar = argv[4][0];
    for(int iChild = 0; iChild < argc - 4; iChild++) {
      if(fork() == 0) {
	nice(iChild*niceIncr);
	//printf("%d %c %d \n",iChild*niceIncr, argv[iChild + 4][0], getpriority(PRIO_PROCESS, 0));
	//PrintCharacters(printMethod, numOfTimes, argv[iChild + 4][0]);  // Print character printChar numOfTimes times using method printMethod
	execl("/home/student/exercises/ex01/ex02/display", "display", argv[1], argv[2], argv[iChild + 4], (char*)NULL);
	perror("here ded");
	exit(0);
      }
    }
    for(int iChild = 0; iChild < argc - 4; iChild++) {
      wait(NULL);
    }
    printf("All children have finished");
  }
  
  printf("\n");  // Newline at end
  return 0;
}
