#include <stdio.h>
#include <sys/semaphore.h>
#include <unistd.h>
long long sum=0;
#define counter 100000000
sem_t mutex;
void *compute(int offset){
        for(long long  i=0;i<counter;i++) {
                sem_wait(&mutex);
                sum=sum+offset;
                sem_post(&mutex);
        }
        pthread_exit(1);
}
int main() {
        sem_init(&mutex,0,1);
        pthread_t thread_id1;
        pthread_t thread_id2;
        pthread_create(&thread_id1,NULL,compute,1);
        pthread_create(&thread_id2,NULL,compute,-1);
        pthread_join(thread_id1, NULL);
        pthread_join(thread_id2, NULL);
        sem_destroy(&mutex);
        printf("Thread stopped with sum=%lld\n",sum);
        return 0;
}
