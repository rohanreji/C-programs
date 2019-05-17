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
int main() {
        key_t key;
        int msgid;
        struct pirate_msgbuf pmb;
        key=ftok("./message",'b');
        msgid=msgget(key, 0666 | IPC_CREAT);
        //messageid, struct, sizeof struct, mtype, flags
        msgrcv(msgid, &pmb, sizeof(struct info),2, 0);
        printf("received: %s\n",pmb.info_t.name);
        //to clean the message queue
        msgctl(msgid, IPC_RMID, NULL);
        return 0;
}
