#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, seekTime = 0, n, head, queue[20], temp, maxTrack, currentTrack, direction, maxRequest;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the elements of disk request queue\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the maximum track number: ");
    scanf("%d", &maxTrack);

    printf("Enter the direction of disk movement (0: for left, 1: for right): ");
    scanf("%d", &direction);

    printf("\n");

    queue[n] = head;
    n = n + 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(queue[j] > queue[j + 1]) {
                temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    maxRequest = queue[n - 1];

    for(i = 0; i < n; i++) {
        if(head == queue[i]) {
            currentTrack = i;
            break;
        }
    }

    if (direction == 0) {
        printf(" ------------------ Seek sequence for left movement of disk is ----------------- \n\n");
        for(i = currentTrack; i >= 0; i--) {
            if(queue[i] == head) {
                printf(" %d -->", head);
                continue;
            }
            printf(" %d - -> ", queue[i]);
        }
        printf("0 - -> ");
        for(i = currentTrack + 1; i < n; i++) {
            if(queue[i] == head) {
                i = i + 1;
            }
            printf("%d - -> ", queue[i]);
        }
        seekTime = head + maxRequest;
    } else {
        printf("---------------- Seek sequence for right movement of disk is ------------------ \n\n");
        for(i = currentTrack; i < n; i++) {
            printf(" %d - -> ", queue[i]);
        }
        printf("%d - -> ", maxTrack);
        for(i = currentTrack - 1; i >= 0; i--) {
            printf("%d - -> ", queue[i]);
        }
        seekTime = (maxTrack - head) + (maxTrack - queue[0]);
    }

    printf("\n The total distance traveled (in cylinders) by the disk-arm using SCAN = %d", seekTime);

    return 0;
}
