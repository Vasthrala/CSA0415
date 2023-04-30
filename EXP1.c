#include <stdio.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int main() {
    int i, j;
    int available[NUM_RESOURCES] = {9, 3, 6};
    int claim[NUM_PROCESSES][NUM_RESOURCES] = {
        {3, 2, 2},
        {6, 1, 3},
        {3, 1, 4},
        {4, 2, 2}
    };
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
        {1, 0, 0},
        {6, 1, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    int need[NUM_PROCESSES][NUM_RESOURCES];
    int finish[NUM_PROCESSES] = {0};
    int work[NUM_RESOURCES];

    
    for (i = 0; i < NUM_PROCESSES; i++) {
        for (j = 0; j < NUM_RESOURCES; j++) {
            need[i][j] = claim[i][j] - allocation[i][j];
        }
    }

    
    for (i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    
    int count = 0;
    int safe_sequence[NUM_PROCESSES];
    while (count < NUM_PROCESSES) {
        int found = 0;
        for (i = 0; i < NUM_PROCESSES; i++) {
            if (finish[i] == 0) {
                int can_allocate = 1;
                for (j = 0; j < NUM_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                if (can_allocate)
				 {
                    
                    for (j = 0; j < NUM_RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    safe_sequence[count] = i;
                    count++;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in an unsafe state.\n");
            return 0;
        }
    }
    printf("System is in a safe state.\n");
    printf("Safe sequence: ");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");

    return 0;
}
