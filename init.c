#include <stdio.h>
#include "syscall.h"


int main() {
        int i=0;
	i=spawn("./bar.so");
	printf("./bar.so lance : %d\n",i);
	i=spawn("./foo.so");
	printf("./foo.so lance : %d\n",i);
	i=spawn("./wait.so");
	printf("./wait.so lance : %d\n",i);
	i=spawn("./signal.so");
	printf("./siganl.so lance : %d\n",i);
	
	while (1) {
	      printf("init %d\n",mlk_clock());
	      //for (i=0;i<100000000;i++);
	      //mlk_signal(i);
	      mlk_sleep(10);
	      mlk_print("10 secondes sont passés");
	      mlk_send("le 1 message",12, 2);
	  }

}
