#include <stdio.h>
#include <pthread.h>
#include"mythreads.h"
int flag[2];
int turn;
const int MAX = 1e9;
int ans = 0;
  
void lock_init()
{
    flag[0] = flag[1] = 0;
    turn = 0;
}
void lock(int self)
{

    flag[self] = 1;
    turn = 1-self;

    // to acquire lock or it is your turn to get the lock.
    while (flag[1-self]==1 && turn==1-self) ;
}
  

void unlock(int self)
{
    flag[self] = 0;
}

void* func(void *s)
{
    int i = 0;
    int self = (int*)s;
    printf("Thread Entered: %d\n", self);
    lock(self);
    for (i=0; i<MAX; i++)
        ans++;
  
    unlock(self);
}


int main()
{
    // Initialized the lock then fork 2 threads
    pthread_t p1, p2;
    lock_init();
  
    // Create two threads (both run func) 
    pthread_create(&p1, NULL, func, (void*)0);
    pthread_create(&p2, NULL, func, (void*)1);
  
    // Wait for the threads to end.
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
  
    printf("Actual Count: %d | Expected Count: %d\n", ans, MAX*2);
    return 0;
}
