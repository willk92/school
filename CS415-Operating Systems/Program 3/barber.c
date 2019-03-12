#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

const int CHAIRS = 5;

int qtyClientsWaiting = 0;
int qtyClientsTurnedAway = 0;
int qtyClientsServiced = 0;

sem_t clients;
sem_t barbers;
sem_t mutex;

void* pthBarber();
void* pthClient(int *param);
double distNormalRandom();

struct strcClient {
    int id;
};

int main() {
    sem_init(&clients, 1, 0);
    sem_init(&barbers, 1, 0);
    sem_init(&mutex, 1, 1);

    srand(time(NULL));

    pthread_t tBarber, tClient;

    pthread_create(&tBarber, NULL, (void *) pthBarber, NULL);

    int i = 0;

    time_t endwait;
    time_t start = time(NULL);
    time_t seconds = 30;

    endwait = start + seconds;

    printf("Program will simulate 30 seconds\n");

    while (start < endwait) {
        struct strcClient client;
        client.id = ++i;

        pthread_create(&tClient, NULL, (void *) pthClient, &client.id);

        sleep(distNormalRandom());
        start = time(NULL);
    }

    printf("\nClients serviced: %d", qtyClientsServiced);
    printf("\nClients turned away: %d", qtyClientsTurnedAway);

    return 0;
}

void* pthClient(int *param) {
    sem_wait(&mutex);

    if (qtyClientsWaiting < CHAIRS) {
        qtyClientsWaiting++;

        sem_post(&clients);
        sem_post(&mutex);

        sem_wait(&barbers);
    }
    else {
        sem_post(&mutex);

        qtyClientsTurnedAway++;
        qtyClientsWaiting = CHAIRS;
    }

    pthread_exit(NULL);
}

void* pthBarber() {
    while(1) {
        sem_wait(&clients);
        sem_wait(&mutex);

        qtyClientsWaiting--;
        qtyClientsServiced++;

        sem_post(&barbers);
        sem_post(&mutex);

        sleep(3);
    }

    pthread_exit(NULL);
}

double distNormalRandom() {
    double res;
    do {
      res = 1.0 + 1.5 * sqrt(-2 * log((rand()+1.0) / (RAND_MAX+1.0))) * cos(2 * 3.14 * (rand()+1.0) / (RAND_MAX+1.0));
    }
    while (res <= 1.0 || res >= 3.0);

    return res;
}

// Program will simulate 30 seconds

// Clients serviced: 11
// Clients turned away: 6

// ...Program finished with exit code 0
// Press ENTER to exit console.