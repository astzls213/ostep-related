/* 通过条件变量和互斥锁来实现信号量 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

typedef struct __Zem_t
{
    int value;
    pthread_cond_t cond;
    pthread_mutex_t lock;

} zem_t;


