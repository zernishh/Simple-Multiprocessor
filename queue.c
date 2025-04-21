// Provides implementations of Queue functions 
// Manages queue initialisation, enqueue (from TaskFile), dequeue (for cpu() functions)

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int queue_limit;
Task ready_queue[MAX_QUEUE_SIZE];
int queue_size = 0;
int front = 0, rear = -1; // pointers for front and rear of the Queue

// Initialize the queue
void init_queue(int limit) {
    queue_limit = limit;
    queue_size = 0;
    front = 0;
    rear = -1;
}

// Enqueue a task
// Requires all 3 parameters from task struct (queue.h)
void enqueue(int task_no, int burst_time, time_t arrival_time) {
    if (queue_size < queue_limit) {
        rear = (rear + 1) % queue_limit; // moves rear pointer forward, queue wraps around
        ready_queue[rear].task_no = task_no;
        ready_queue[rear].burst_time = burst_time;
        ready_queue[rear].arrival_time = arrival_time; // Store the arrival time
        queue_size++;
        
    } else { // if queue full
        fprintf(stderr, "Queue is full. Cannot enqueue task %d.\n", task_no);
    }
}

// Dequeue a task
// Removes and returns Task at front of queue
Task dequeue() {
    Task task = {-1, 0, 0}; // Initialize with default values (indicating invalid if -1)
    if (queue_size > 0) {
        task = ready_queue[front]; // retrieve front task 
        front = (front + 1) % queue_limit; // moves front pointer forward in circular manner 
        queue_size--;
    } else { // if queue empty 
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
    }
    return task;
}


