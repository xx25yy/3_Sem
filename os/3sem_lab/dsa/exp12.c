#include <stdio.h>
#include <stdlib.h>

int *ht, n, m, idx, count = 0;

void insert(int key) {
    idx = key % m;
    while (ht[idx] != -1) {
        idx = (idx + 1) % m;
    }
    ht[idx] = key;
    count++;
}

void display() {
    int i;
    if (count == 0) {
        printf("\nHash Table is empty");
        return;
    }
    printf("\nHash Table contents are:\n");
    for (i = 0; i < m; i++) {
        printf(" T[%d] --> %d\n", i, ht[i]);
    }
}

int main() {
    int i;
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the number of memory locations (m) for the hash table (should be greater than or equal to N): ");
    scanf("%d", &m);

    if (m < n) {
        printf("\nWarning: m is less than N. Setting m to N.\n");
        m = n;
    }

    ht = (int *)malloc(m * sizeof(int));

    for (i = 0; i < m; i++) {
        ht[i] = -1;
    }

    printf("\nEnter the key values for N Employee Records:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ht[i]);
    }

    for (i = 0; i < n; i++) {
        if (count == m) {
            printf("\n~~~Hash table is full. Cannot insert the record %d key~~~", i + 1);
            break;
        }
        insert(ht[i]);
    }

    display();

    return 0;
}
