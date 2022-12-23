#ifndef __PH_DIN__
#define __PH_DIN__
#include<semaphore.h>
#define N 5
extern sem_t chopstick[N];
extern int philosopher_id[N];

void* philo (void* n); // n is the number of the philosopher
void  eat(int ph);

#endif