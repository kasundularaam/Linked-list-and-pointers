//21UG1073

#include <stdio.h>
#include <stdlib.h>

int main() {
    char letters[] = {'A', 'N', 'I', 'M', 'A', 'L'};
    Node *head = create_linked_list(letters, 6);
    
    print_linked_list(head);
    
    insert_node(head, 'D');
    
    print_linked_list(head);
    
    insert_node_at_end(head, 'S');
    
    print_linked_list(head);
    
    delete_node(head, 'N');
    
    print_linked_list(head);

    Stack *s = linked_list_to_stack(head);
    print_stack(s);
    
    // Free the memory allocated for the linked list
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}

//21UG1073

typedef struct node {
    char data;
    struct node *next;
} Node;

//21UG1073

typedef struct stack {
    Node *top;
} Stack;

//21UG1073

void push(Stack *s, char value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

char pop(Stack *s) {
    if (s->top == NULL) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    
    Node *temp = s->top;
    char value = temp->data;
    s->top = temp->next;
    free(temp);
    
    return value;
}

//21UG1073

void print_stack(Stack *s) {
    printf("Stack contents: ");
    Node *current = s->top;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

//21UG1073

Stack *linked_list_to_stack(Node *head) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    
    Node *current = head;
    while (current != NULL) {
        push(s, current->data);
        current = current->next;
    }
    
    return s;
}

//21UG1073

void print_linked_list(Node *head) {
    printf("List contents: ");
    Node *current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

//21UG1073

void insert_node(Node *head, char value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    
    Node *slow_ptr = head;
    Node *fast_ptr = head->next;
    
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    
    new_node->next = slow_ptr->next;
    slow_ptr->next = new_node;
}

//21UG1073

void insert_node_at_end(Node *head, char value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

//21UG1073

void delete_node(Node *head, char value) {
    Node *current = head;
    Node *prev = NULL;
    
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Node with value '%c' not found\n", value);
        return;
    }
    
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
}

//21UG1073

Node *create_linked_list(char *values, int size) {
    Node *head = NULL;
    
    for (int i = 0; i < size; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = values[i];
        new_node->next = NULL;
        
        if (head == NULL) {
            head = new_node;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    
    return head;
}

//21UG1073

// Linked List allows easy insertion and deletion
// of elements in the middle of the list,
// whereas a stack only allows
// for insertion and deletion at the top