#include "common_threads.h"

zem_t s;

void *child(void *arg) {
    printf("child\n");
    // use semaphore here
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    printf("parent: begin\n");
    // init semaphore here
    Pthread_create(&p, NULL, child, NULL);
    // use semaphore here
    printf("parent: end\n");
    return 0;
}

