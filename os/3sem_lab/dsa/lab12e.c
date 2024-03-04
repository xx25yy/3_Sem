/*Given a File of N employee records with a set K of Keys(4-digit) which uniquely determine the
records in file F. Assume that file F is maintained in memory by a Hash Table(HT) of m
memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let
the keys in K and addresses in L are Integers. Design and develop a Program in C that uses
Hash function H: K L as H(K)=K mod m (remainder method), and implement hashing
technique to map a given key K to the address space L. Resolve the collision (if any)
using linear probing*/#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct employee {
    int id;
    char name[15];
};
typedef struct employee EMP;

EMP emp[MAX];
int a[MAX];

void Linear_prob(int key, int num) {
    int i = key, flag = 0;
    
    if (a[i] == -1)
        flag = 1;
    else {
        i = (key + 1) % MAX;
        while (i != key && flag == 0) {
            if (a[i] == -1) {
                flag = 1;
                break;
            }
            else
                i = (i + 1) % MAX;
        }
    }
    
    if (flag == 0)
        printf("\nHash table is full");
    else {
        printf("\nEnter emp id: ");
        scanf("%d", &emp[i].id);
        printf("Enter emp name: ");
        scanf("%s", emp[i].name);
        a[i] = i;
        printf("\nCollision avoided successfully using LINEAR PROBING\n");
    }
}

void Display() {
    int i, ch;
    printf("\n1. Display ALL\n2. Filtered Display\nEnter the choice: ");
    scanf("%d", &ch);
    printf("\nHTKey\tEmpID\tEmpName");
    for (i = 0; i < MAX; i++) {
        if (ch == 2 && a[i] == -1)
            continue;
        else
            printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
    }
}

int main() {
    int num, key, i, ch = 1;
    printf("Collision handling by linear probing: ");
    for (i = 0; i < MAX; i++)
        a[i] = -1;

    do {
        printf("\nEnter the data: ");
        scanf("%d", &num);
        Linear_prob(num % 100, num);
        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &ch);
    } while (ch);

    Display();
    return 0;
}
