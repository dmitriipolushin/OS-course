#include <stdio.h>
#include <pthread.h>

void *forThread(void *a)
{
    int *p = (int*)a;
    printf("this is thread number %d\n", *p);
    pthread_exit(0);
}

int main(int argc, char const *argv[])
{
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        pthread_t thread_id; 
        pthread_create(&thread_id, NULL, forThread, &i);
        printf("thread %d is created\n", i);
        pthread_join(thread_id, NULL);
        printf("thread %d exits\n", i);
    }
    
    return 0;
}
