/*
This is a solution to dinning philosopher problems

the structure of philosopher i

do {

    wait (chopstick[i]);
    wait(chopstick[(i+1)%5]);
    ....
    //eat

    signal(chopstick[i]);
    signal(chopstick[(i+1)%5]);

    //think
    
}

At the begining let's say that all  chopstick are avalaible so semaphores are all 
initialize to 1.

And when one chopstick in take by a philosopher so the associate semaphore will be set to 0

useful link  :  https://www.youtube.com/watch?v=FYUi-u7UWgw
                https://www.youtube.com/watch?v=27lu1lwvoGY

*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include "../include/dining.h"

int main(int argc, char** argv)
{

    int i;
    pthread_t tid [N];

    // initialization of the semaphores
    for (i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);
    
    // thread creation
    
    for(i = 0; i < N; i++) {
        philosopher_id[i] = i; 
       int res1 = pthread_create(tid+i, NULL,philo,(void*)&philosopher_id[i]);

       if(res1 != 0)
       {
        printf(" Thread creation failed !!!\n");
       }
    }

    for(i = 0; i< N; i++ )
    {
        int res2 = pthread_join(tid[i], NULL);
        if(res2 != 0)
        {
            printf("Thread joining failed !!!\n");
        }
    }

    pthread_exit(NULL);

    return 0;
}


