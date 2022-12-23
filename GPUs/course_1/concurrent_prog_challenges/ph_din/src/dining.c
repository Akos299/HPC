#include "../include/dining.h"
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>

sem_t chopstick[N];
int philosopher_id[N];
void * philo(void* n)
{


    int ph = *((int*)n);
    printf("Philosopher %d wants to eat\n", ph) ;
    printf("Philosopher %d try to pick its left chopstick \n", ph) ;
    sem_wait(&chopstick[ph]);
    printf("Philosopher %d takes its left chopstick \n", ph) ;
    printf("Philosopher %d try to pick its right chopstick \n", ph) ;
    sem_wait(&chopstick[(ph+1)%N]);
    printf("Philosopher %d takes its right chopstick \n", ph) ;

    eat(ph);
    sleep(3);    // get other threads to execute
    printf("Philosopher %d has finished to eat \n", ph) ;
    sem_post(&chopstick[(ph+1)%N]);
    printf("Philosopher %d leaves its right chopstick \n", ph) ;
    sem_post(&chopstick[ph]);
    printf("Philosopher %d leaves its left chopstick \n", ph) ;
}

void eat(int ph)
{
    printf("Philosopher %d is eating \n",ph);
}