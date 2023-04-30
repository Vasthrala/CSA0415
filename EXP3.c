#include <stdio.h>

#define NUM_PROCESSES 4

struct process {
    int pid;        
    int burst_time; 
    int waiting_time; 
    int turnaround_time; 
};

int main() {
    int i, j, min;
    struct process temp;
    float total_waiting_time = 0, total_turnaround_time = 0, average_waiting_time, average_turnaround_time;
    struct process processes[NUM_PROCESSES] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0}
    };

    for (i = 0; i < NUM_PROCESSES - 1; i++) {
        min = i;
        for (j = i + 1; j < NUM_PROCESSES; j++) {
            if (processes[j].burst_time < processes[min].burst_time) {
                min = j;
            }
        }
        temp = processes[i];
        processes[i] = processes[min];
        processes[min] = temp;
    }
    processes[0].turnaround_time = processes[0].burst_time;
    for (i = 1; i < NUM_PROCESSES; i++) {
        processes[i].waiting_time = processes[i-1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
    for (i = 0; i < NUM_PROCESSES; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    average_waiting_time = total_waiting_time / NUM_PROCESSES;
    average_turnaround_time = total_turnaround_time / NUM_PROCESSES;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}
