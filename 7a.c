#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int i = *(int*)num;

    pthread_mutex_lock(&chopstick[i]);
    pthread_mutex_lock(&chopstick[(i+1)%N]);

    printf("Philosopher %d is Eating\n", i);

    pthread_mutex_unlock(&chopstick[i]);
    pthread_mutex_unlock(&chopstick[(i+1)%N]);

    return NULL;
}

int main() {
    pthread_t ph[N];
    int i, a[N];

    for(i = 0; i < N; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    for(i = 0; i < N; i++) {
        a[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &a[i]);
    }

    for(i = 0; i < N; i++)
        pthread_join(ph[i], NULL);

    return 0;
}
