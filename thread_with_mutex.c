#include <stdio.h>

long long sum=0;
#define counter 100000000
pthread_mutex_t lock;
void *compute(int offset){
        for(long long  i=0;i<counter;i++) {
                pthread_mutex_lock(&lock);
                sum=sum+offset;
                pthread_mutex_unlock(&lock);
        }
        pthread_exit(1);
}
int main() {
        pthread_mutex_init(&lock, NULL);
        pthread_t thread_id1;
        pthread_t thread_id2;
        pthread_create(&thread_id1,NULL,compute,1);
        pthread_create(&thread_id2,NULL,compute,-1);
        pthread_join(thread_id1, NULL);
        pthread_join(thread_id2, NULL);
        printf("Thread stopped with sum=%lld\n",sum);
        return 0;
}
