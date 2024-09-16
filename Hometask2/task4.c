#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <unistd.h>

int main(void)
{
  while(1){
    if (getchar() == '\n') {
      printf("Enter key is pressed");
      sleep(1); //wait for check printed message.
      break;
    }
  }
  return 0;
}