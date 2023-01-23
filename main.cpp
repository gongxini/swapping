#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS  10

void* do_memory(void* arg) {
  unsigned int size = 1000000000;
  char *buf = (char *)malloc(size);
  if(buf)
    printf("get the malloc\n");

  sleep(60);

  return 0;
}


int main() {
  pthread_t threads[NUM_THREADS];
  int arg[NUM_THREADS];
  int i;
  //  pthread_mutex_init(&mutex, NULL);

  for(i = 0; i<NUM_THREADS;i++) {
    arg[i] = i;
  }
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_create (&threads[i], NULL, do_memory, &arg[i]);
  }

  for (i = 0; i < NUM_THREADS; i++)
  {
    pthread_join (threads[i], NULL);
  }
  return 0;
}
