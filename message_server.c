#include <stdio.h>
#include <sys/msg.h>
struct info {
        int num;
        char name[30];
};
struct pirate_msgbuf {
        long mtype;
        struct info info_t;
};

int main(int argc, char *argv[]){
        struct pirate_msgbuf pmb = {2,{120,"Rohan Reji"}};
        key_t key = ftok("./message",'b');
        int msgid = msgget(key, 0666|IPC_CREAT);
        printf("Sending pirate: %s\n",pmb.info_t.name);
        msgsnd(msgid, &pmb, sizeof(struct info), 0);
        return 0;
}
