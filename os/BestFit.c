#include<stdio.h>

int main() {
    int i, nb, np, block_size[20], process_size[20], rm[20], allocation[20];

    printf("\n\t-------->Memory Management Scheme-BestFit >");
    printf("\n\nEnter the number of free blocks in Main memory: ");
    scanf("%d", &nb);
    printf("Enter the number of processes to be stored in Main memory: ");
    scanf("%d", &np);

    printf("\n Enter the size (MB) of the memory blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d size in MB: ", i + 1);
        scanf("%d", &block_size[i]);
    }

    printf("\nEnter the size of the Process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d size in MB: ", i + 1);
        scanf("%d", &process_size[i]);
    }

    for (i = 0; i < np; i++) {
        allocation[i] = -1;
    }

    for (i = 0; i < np; i++) {
        int indexPlaced = -1;
        for (int j = 0; j < nb; j++) {
            if (block_size[j] >= process_size[i]) {
                if (indexPlaced == -1 || block_size[j] < block_size[indexPlaced]) {
                    indexPlaced = j;
                }
            }
        }
        if (indexPlaced != -1) {
            allocation[i] = indexPlaced;
            block_size[indexPlaced] -= process_size[i];
            rm[i] = block_size[indexPlaced];
        }
    }

    printf("\nProcess No.\tProcess Size(MB)\t\t Allocated Block no\t\t Remaining block memory size\n");
    for (i = 0; i < np; i++) {
        printf("%d \t\t\t %d \t\t\t\t ", i + 1, process_size[i]);
        if (allocation[i] != -1) {
            printf("%d\t\t", allocation[i] + 1);
            printf("\t\t%d\n", rm[i]);
        } else {
            printf("Not Allocated\n");
        }
    }
    return 0;
}
