#include <stdio.h>
#include <sys/ipc.h>

#define NOT_READY -1
#define FILED 0
#define TAKEN 1
struct Memory{
        int status;
        char data[4];
};

int main() {
        key_t shmkey;
        int shmid;
        struct Memory *mem;
        shmkey=ftok("./shm",'b');
        shmid = shmget(shmkey,sizeof(struct Memory), 0666|IPC_CREAT);
        mem = (struct Memory*)shmat(shmid, NULL, 0);
        while(mem->status != FILED);
        printf("\n received: %s \n",mem->data);
        mem->status = TAKEN;
        shmdt((void*)mem);
        return 0;
}
