#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 1

static int buffer[MAX];
static int number = 0;
static int end = 0;
static int producerSleep;
static int consumerSleep;

void *producer(void *vararg){
    while (1) {
        if (end == MAX){
            producerSleep = 1;
        }
        while (1){
            if (producerSleep == 0){
                break;
            }
        };
        number++;
        buffer[end] = number;
        end++;
        printf("Producer added %d, top is %d\n", number, end);
        consumerSleep = 0;
    }
    pthread_exit(0);
}

void *consumer(void *vararg){
    while (1){
        if (end == 0){
            consumerSleep = 1;
        }
        while (1){
            if (consumerSleep == 0){
                break;
            }
        };
        printf("Comsumer removed %d, top now is %d\n", buffer[end - 1], end - 1);
        buffer[end - 1] = 0;
        end = end - 1;
        producerSleep = 0;
    }
    pthread_exit(0);
}

int main()
{
    /*
    do not know how to pint a number just one time in a minute
    */
    pthread_t t1, t2;
    producerSleep = 0;
    consumerSleep = 0;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}