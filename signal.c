#include "syscall.h"
void main() {
   int p;

   p=spawn("./wait.so");
   while (1) {
          mlk_print("J'envoie un signal");
          mlk_signal(p);
          mlk_sleep(1);
}
}
