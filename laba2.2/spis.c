#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // Пусть в качестве данных у нас будут числа
    struct node *next; // Указатель на следующий узел, если нет узла = NULL
};

void append(struct node **head, int newData) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head;

    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }


    last->next = newNode;
}

void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int input;

    printf("Введите числа:\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        append(&head, input);
    }

    printf("Список: ");
    printList(head);

    return 0;
}
