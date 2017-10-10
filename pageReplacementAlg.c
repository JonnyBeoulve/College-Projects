/*||Name: Jonathan Leack
||||Description: This program will utilize Collatz conjecture to sequence an integer down to one.*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

int main(int argc,  char *argv[])
{

  //Check if correct command line format was followed
  if(argc != 2) {
    printf("ERROR: Please provide a single integer during execution.\n");
    return -1;
  }

  //Convert passed value to integer
  int n = atoi(argv[1]);

  //Check if integer is within supported boundaries
  //Note: Upper and lower limit can be specified here
  if(n < 2 || n > 999) {
    printf("ERROR: Please provide a value greater than 1 and less than 1000\n");
    return -1;
  }

  //Wait Parent before creating Child process
  wait();
  pid_t pid = fork();

  //While value doesn't equal 1, display current value of n and apply Collatz
  while (n != 1) {
    printf("%d, ", n);

    if(n % 2 == 1)
      n = 3 * n + 1;
    else
      n = n / 2;
  }

  //End line for readability and kill child process
  printf("%d.\n", n);
  kill(pid, SIGKILL);

  return 0;

}
