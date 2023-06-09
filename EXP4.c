#include <stdio.h>

#define NUM_PARTITIONS 6

int main() {
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int num_processes = 5;
    int processes[] = {115, 500, 358, 200, 375};
    
    printf("Initial memory partitions:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d KB ", partitions[i]);
    }
    printf("\n");
    for (int i = 0; i < num_processes; i++) {
        int j;
        for (j = 0; j < NUM_PARTITIONS; j++) {
            if (processes[i] <= partitions[j]) {
                printf("Process %d (size %d KB) allocated to partition %d (size %d KB)\n",
                    i + 1, processes[i], j + 1, partitions[j]);
                partitions[j] -= processes[i];
                break;
            }
        }
        if (j == NUM_PARTITIONS) {
            printf("Process %d (size %d KB) cannot be allocated\n", i + 1, processes[i]);
        }
    }
    
    printf("Final memory partitions:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d KB ", partitions[i]);
    }
    printf("\n");
    
    return 0;
}
