#include <stdio.h>

#define EMPTY -1

int table[100];

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
int search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == EMPTY)
            return 0;

        i++;
    }
    return 0;
}

int main() {
    int m, n;
    char op[10];
    int key;

    printf("Enter table size: ");
    scanf("%d", &m);

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key, m);
        } else if (op[0] == 'S') {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}