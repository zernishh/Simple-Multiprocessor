# Simple Multiprocessor Scheduling Simulation (SMSS)

⚠️ *Note: Full implementation restricted. Contact for details.*  

## Overview
This program simulates a multiprocessor scheduling system using POSIX Pthreads, allowing for task scheduling from an input file and management of task execution in a FIFO queue.

## Prerequisites
- GCC compiler
- POSIX Threads library

## Steps to Compile and Run

### Step 1: Generate the Task File
Before running the main scheduling simulation, you need to generate the task file. Use the `createTasks.c` program to create this file.

1. **Compile createTasks.c :**
   ```bash
   gcc -std=c99 -o createTasks createTasks.c
   
   then to run
   ./createTasks
   
2. **Compile the main codes for simulation using makefile :**
   ```bash
   make
   
   then to run
   ./smss TaskFile.txt m n

   m: The maximum size of the FIFO ready queue (an integer) min 1, max 3
   n: The number of CPU threads (an integer). min 1, max 5
   
   **Example usage :**
   ./smss TaskFile.txt 3 2
   This example runs the simulation with a maximum queue size of 3 and 2 CPU threads.
   
3. After the program completes execution, you can check the LogFile.txt for a summary of task processing, including waiting times and turnaround times.
   
   
   
