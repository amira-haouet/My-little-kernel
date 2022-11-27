#include <stdio.h>
#include "syscall.h"

void main() {
  int i=0;
  while (1) {
    printf("foo %d\n",mlk_clock());
    //mlk_wait();
//    for (i=0;i<100000000;i++);
    mlk_sleep(5);
    mlk_print("5 secondes sont passés");
    mlk_recv("le 1 message",12);
    }
}

