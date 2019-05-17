#include <stdio.h>
#include <sys/ipc.h>
#define NOT_READY -1
#define FILED 0
#define TAKEN 1
struct Memory{
        int status;
        char data[4];
};
int main(){
        key_t shmkey;
        int shmid;
        struct Memory *mem;
        shmkey = ftok("./shm",'b');
        shmid = shmget(shmkey,sizeof(struct Memory), 0666 |IPC_CREAT);
        mem = (struct Memory*)shmat(shmid, NULL, 0);
        mem->status = NOT_READY;
        strcpy(&(mem->data),"Rohan");
        mem->status = FILED;
        while(mem->status!=TAKEN);
        shmdt((void*)mem);
        shmctl(shmid, IPC_RMID, NULL);
        return 0;
}
