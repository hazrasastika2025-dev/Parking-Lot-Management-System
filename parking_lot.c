
#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 211

#define EMPTY 0
#define USED 1
#define DELETED 2

typedef struct {
    char id[20];
    int slot, state;
} Entry;

Entry map[SIZE];

char lot[MAX][20];
char queue[MAX][20];
char history[MAX][20];

int front = 0, rear = 0, count = 0;
int top = -1, capacity;

/* Hash function */
int hash(char *s) {
    unsigned h = 0;

    while (*s)
        h = (h * 31 + (unsigned char)*s++) % SIZE;

    return (int)h;
}

/* Search vehicle */
int find(char *id) {
    int h = hash(id);

    for (int i = 0; i < SIZE; i++) {
        int p = (h + i) % SIZE;

        if (map[p].state == EMPTY)
            return -1;

        if (map[p].state == USED &&
            strcmp(map[p].id, id) == 0)
            return p;
    }

    return -1;
}

/* Insert vehicle into hash map */
void insert(char *id, int slot) {
    int h = hash(id), deleted = -1;

    for (int i = 0; i < SIZE; i++) {
        int p = (h + i) % SIZE;

        if (map[p].state == USED &&
            strcmp(map[p].id, id) == 0) {
            map[p].slot = slot;
            return;
        }

        if (map[p].state == DELETED && deleted == -1)
            deleted = p;

        if (map[p].state == EMPTY) {
            if (deleted != -1)
                p = deleted;

            strcpy(map[p].id, id);
            map[p].slot = slot;
            map[p].state = USED;
            return;
        }
    }

    if (deleted != -1) {
        strcpy(map[deleted].id, id);
        map[deleted].slot = slot;
        map[deleted].state = USED;
    }
}

/* Remove vehicle from hash map */
void removeEntry(char *id) {
    int p = find(id);

    if (p != -1)
        map[p].state = DELETED;
}

/* Find available parking slot */
int freeSlot(void) {
    for (int i = 0; i < capacity; i++) {
        if (lot[i][0] == '\0')
            return i;
    }

    return -1;
}

/* Add vehicle to waiting queue */
void enqueue(char *id) {
    if (count == MAX) {
        printf("Waiting queue is full.\n");
        return;
    }

    strcpy(queue[rear], id);
    rear = (rear + 1) % MAX;
    count++;

    printf("Vehicle added to waiting queue.\n");
}

/* Assign waiting vehicle to free slot */
void dequeueToSlot(int slot) {
    char id[20];

    if (count == 0)
        return;

    strcpy(id, queue[front]);

    front = (front + 1) % MAX;
    count--;

    strcpy(lot[slot], id);
    insert(id, slot);

    printf("%s assigned to slot %d.\n",
           id, slot + 1);
}

/* Vehicle entry */
void entry(void) {
    char id[20];
    int slot;

    printf("Enter vehicle number: ");
    scanf("%19s", id);

    if (find(id) != -1) {
        printf("Vehicle is already parked.\n");
        return;
    }

    slot = freeSlot();

    if (slot == -1)
        enqueue(id);
    else {
        strcpy(lot[slot], id);
        insert(id, slot);

        printf("Vehicle parked in slot %d.\n",
               slot + 1);
    }
}

/* Vehicle exit */
void exitVehicle(void) {
    char id[20];
    int p, slot;

    printf("Enter vehicle number: ");
    scanf("%19s", id);

    p = find(id);

    if (p == -1) {
        printf("Vehicle not found in parking lot.\n");
        return;
    }

    slot = map[p].slot;

    lot[slot][0] = '\0';
    removeEntry(id);

    if (top < MAX - 1)
        strcpy(history[++top], id);

    printf("%s exited from slot %d.\n",
           id, slot + 1);

    dequeueToSlot(slot);
}

/* Display parking status */
void display(void) {
    printf("\nPARKING STATUS\n");

    for (int i = 0; i < capacity; i++) {
        printf("Slot %d: %s\n",
               i + 1,
               lot[i][0] ? lot[i] : "EMPTY");
    }

    printf("Waiting queue: ");

    if (count == 0)
        printf("Empty");

    for (int i = 0; i < count; i++) {
        printf("%s ",
               queue[(front + i) % MAX]);
    }

    printf("\n");
}

/* Main function */
int main(void) {
    int choice;

    printf("Enter parking-lot capacity (1-%d): ",
           MAX);

    if (scanf("%d", &capacity) != 1 ||
        capacity < 1 || capacity > MAX) {
        printf("Invalid capacity.\n");
        return 1;
    }

    for (int i = 0; i < capacity; i++)
        lot[i][0] = '\0';

    do {
        printf("\n1. Entry");
        printf("\n2. Exit");
        printf("\n3. Display");
        printf("\n4. Exit History");
        printf("\n5. Stop");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                entry();
                break;

            case 2:
                exitVehicle();
                break;

            case 3:
                display();
                break;

            case 4:
                if (top == -1)
                    printf("No exit history.\n");
                else
                    printf("Most recently exited: %s\n",
                           history[top]);
                break;

            case 5:
                printf("Program stopped.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
