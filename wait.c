#include "syscall.h"
void main() {
   while (1) {
          mlk_print("J'attend un signal");
          mlk_wait();
          mlk_sleep(1);
}
}
