#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int coef, ex, ey, ez, flag;
    struct node *link;
};

typedef struct node NODE;

NODE *Insert(int coef, int x, int y, int z, NODE *head) {
    NODE *newnode = (NODE *)calloc(1, sizeof(NODE)), *temp = head;
    newnode->coef = coef;
    newnode->ex = x;
    newnode->ey = y;
    newnode->ez = z;
    newnode->flag = 0;
    if (head == NULL)
        head = newnode;
    else {
        while (temp->link != head) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    newnode->link = head;
    return head;
}

NODE *Read_poly(NODE *head) {
    int ex, ey, ez, coef, n, i;
    printf("\nEnter number of terms in polynomial terms:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter coeff and powers of x, y, z: ");
        scanf("%d%d%d%d", &coef, &ex, &ey, &ez);
        head = Insert(coef, ex, ey, ez, head);
    }
    return head;
}

void Display(NODE *head) {
    NODE *temp = head->link;
    while (temp != head) {
        printf("%+dX^%dY^%dZ^%d", temp->coef, temp->ex, temp->ey, temp->ez);
        temp = temp->link;
    }
}

void Evaluate(int x, int y, int z, NODE *head) {
    NODE *temp = head->link;
    int result = 0;
    while (temp != head) {
        result = result + (temp->coef * pow(x, temp->ex) * pow(y, temp->ey) * pow(z, temp->ez));
        temp = temp->link;
    }
    printf("\n Polynomial result is: %d", result);
}

NODE *Add_poly(NODE *h1, NODE *h2, NODE *h3) {
    NODE *p1 = h1->link, *p2;
    do {
        p2 = h2->link;
        do {
            if ((p1->flag != 1) && (p2->flag != 1) && (p1->ex == p2->ex) && (p1->ey == p2->ey) && (p1->ez == p2->ez)) {
                h3 = Insert(p1->coef + p2->coef, p1->ex, p1->ey, p1->ez, h3);
                p1->flag = 1;
                p2->flag = 1;
            }
            p2 = p2->link;
        } while (p2 != h2);
        p1 = p1->link;
    } while (p1 != h1);
    p1 = h1->link;
    while (p1 != h1) {
        if (p1->flag != 1) {
            h3 = Insert(p1->coef, p1->ex, p1->ey, p1->ez, h3);
            p1->flag = 1;
        }
        p1 = p1->link;
    }
    p2 = h2->link;
    while (p2 != h2) {
        if (p2->flag != 1) {
            h3 = Insert(p2->coef, p2->ex, p2->ey, p2->ez, h3);
            p2->flag = 1;
        }
        p2 = p2->link;
    }
    return h3;
}

int main() {
    NODE *h1 = NULL, *h2 = NULL, *h3 = NULL;
    int ch, x, y, z;
    do {
        printf("\n1.Create 2. Display 3. Add 4. Evaluate 5.Exit\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                h1 = Insert(0, 0, 0, 0, h1);
                h2 = Insert(0, 0, 0, 0, h2);
                h3 = Insert(0, 0, 0, 0, h3);
                printf("\nEnter polynomial to evaluate:\n");
                h1 = Read_poly(h1);
                h2 = Read_poly(h2);
                break;
            case 2:
                printf("\nPolynomial A is:");
                Display(h1);
                printf("\nPolynomial B is:");
                Display(h2);
                break;
            case 3:
                h3 = Add_poly(h1, h2, h3);
                printf("\nPolynomial C is:");
                Display(h3);
                break;
            case 4:
                printf("\n Enter value for x, y, z, terms to evaluate:");
                scanf("%d%d%d", &x, &y, &z);
                Evaluate(x, y, z, h1);
                Evaluate(x, y, z, h2);
                break;
            case 5:
                exit(0);
        }
    } while (1);
    return 0;
}
