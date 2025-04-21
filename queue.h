// This file has data structures, global variables to manage FIFO ready queue
// List of tasks waiting for CPU to exceute 

#ifndef QUEUE_H
#define QUEUE_H

// Header guards
#include <pthread.h> // mutex condition for synchronisation
#include <time.h> // for time related tasks 

#define MAX_QUEUE_SIZE 10
#define MAX_CPU_THREADS 5

typedef struct {
    int task_no;         // Task number
    int burst_time;      // Burst time
    time_t arrival_time; // Arrival time of the task (timestamp)
} Task;

// Global variables for the queue and synchronization
extern pthread_mutex_t lock;             // Declare mutex as extern: lock to protect queue 
extern pthread_cond_t cond;              // Declare condition variable as extern: used for signalling
extern int queue_size;                   // Queue size variable declaration
extern int queue_limit;                  // Queue limit variable declaration
extern Task ready_queue[MAX_QUEUE_SIZE]; // Declare ready_queue as extern

// Function declarations
void init_queue(int limit);
void enqueue(int task_no, int burst_time, time_t arrival_time); 
Task dequeue();

#endif // QUEUE_H

