#ifndef SMSS_H
#define SMSS_H

#include <pthread.h>

#define MAX_CPU_THREADS 5  

// Function declarations
void log_event(const char *event, int task_no, int burst_time, const char *cpu, const char *time_type);
void log_summary(int total_tasks, float avg_waiting_time, float avg_turnaround_time);
void get_current_time(char *buffer, size_t size);

#endif // SMSS_H


