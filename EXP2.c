#include <stdio.h>
#define MAX_FRAMES 3

int main() {
    int frames[MAX_FRAMES], page_faults = 0, num_frames = 0, num_pages = 8;
    int page_references[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int i, j, k;
    
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
    for (i = 0; i < num_pages; i++) {
        int page = page_references[i];
        int page_found =0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }
        if (!page_found) {
            frames[num_frames % MAX_FRAMES] = page;
            num_frames++;
            page_faults++;
        }
        printf("Page %d: [", page);
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == -1) {
                printf(" ");
            } else {
                printf("%d", frames[k]);
            }
            if (k < MAX_FRAMES - 1) {
                printf("|");
            }
        }
        printf("]\n");
    }
    printf("Total page faults: %d\n", page_faults);

    return 0;
}
