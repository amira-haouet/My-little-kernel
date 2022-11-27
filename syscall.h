#include <signal.h>
#include <unistd.h>

struct SCC { // System Call Context
        int number;
        union {
                char * s;
                int i;
                int log;

        } u;
        int result;
}; // process fill a SCC struct and set pointer before syscall

typedef struct SCC scc_t;

#ifdef MY_LITLE_KERNEL
extern scc_t * system_call_ctx; // process fill a SCC struct and set pointer before syscall
#else
extern scc_t * system_call_ctx; // process fill a SCC struct and set pointer before syscall

scc_t scc;

int spawn(char *c) {
        scc.number=1;
        scc.u.s=c;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}

int mlk_clock() {
        scc.number=2;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}

int mlk_sleep(int s) {
        scc.number=3;
        scc.u.i=s;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}
int mlk_print(char* msg) {
        scc.number=4;
        scc.u.s=msg;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}
int mlk_signal(int p) {
        scc.number=5;
        scc.u.i=p;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}
int mlk_wait(){
        scc.number=6;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}

mlk_send(char *mesg,int l, int p) {
        scc.number=7;
        scc.u.s=mesg;
        scc.u.i=p;
        scc.u.log=l;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}
mlk_recv(char *buff,int l) {
        scc.number=8;
        scc.u.s=buff;
        scc.u.log=l;
        system_call_ctx=&scc;
        kill(getpid(),SIGUSR1);
        return scc.result;
}
#endif
