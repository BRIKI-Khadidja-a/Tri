/**
 * @file simple_demo.c
 * @brief Version simplifiée pour démonstration
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Compteurs globaux
unsigned long long comparisons = 0;
unsigned long long swaps = 0;

// Structure pour liste chaînée
typedef struct Node {
    char word[50];
    struct Node* next;
} Node;

// Fonctions utilitaires
void reset_counters() {
    comparisons = 0;
    swaps = 0;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_list(Node* head) {
    Node* current = head;
    while (current) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

void print_stats() {
    printf("Comparisons: %llu, Swaps: %llu\n", comparisons, swaps);
}

// Algorithmes de tri pour tableaux
void bubble_sort(int arr[], int size) {
    printf("\n=== Bubble Sort ===\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
        printf("Iteration %d: ", i + 1);
        print_array(arr, size);
    }
}

void selection_sort(int arr[], int size) {
    printf("\n=== Selection Sort ===\n");
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swaps++;
        }
        printf("Iteration %d: ", i + 1);
        print_array(arr, size);
    }
}

// Fonctions pour liste chaînée
Node* create_node(const char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

Node* create_sample_list() {
    const char* words[] = {"banana", "apple", "cherry", "date", "elderberry"};
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < 5; i++) {
        Node* new_node = create_node(words[i]);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

void bubble_sort_list(Node** head) {
    printf("\n=== Bubble Sort for Linked List ===\n");
    if (!*head || !(*head)->next) return;
    
    int swapped;
    do {
        swapped = 0;
        Node* current = *head;
        Node* prev = NULL;
        
        while (current->next) {
            comparisons++;
            if (strcmp(current->word, current->next->word) > 0) {
                // Swap nodes
                if (prev) {
                    prev->next = current->next;
                } else {
                    *head = current->next;
                }
                Node* temp = current->next->next;
                current->next->next = current;
                current->next = temp;
                swapped = 1;
                swaps++;
            }
            prev = current;
            current = current->next;
        }
        printf("After iteration: ");
        print_list(*head);
    } while (swapped);
}

void free_list(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Fonction principale
int main() {
    srand(time(NULL));
    
    printf("=== Professional Sorting Algorithms Demo ===\n");
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Array Sorting Demo\n");
        printf("2. Linked List Sorting Demo\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");
        
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        
        switch (choice) {
            case 1: {
                // Array demo
                printf("\n=== Array Sorting Demo ===\n");
                int size = 8;
                int arr[size];
                
                // Generate random array
                for (int i = 0; i < size; i++) {
                    arr[i] = rand() % 100;
                }
                
                printf("Original array: ");
                print_array(arr, size);
                
                printf("\nChoose algorithm:\n");
                printf("1. Bubble Sort\n");
                printf("2. Selection Sort\n");
                printf("Enter choice (1-2): ");
                
                int algo_choice;
                if (scanf("%d", &algo_choice) != 1) {
                    printf("Invalid input!\n");
                    break;
                }
                
                reset_counters();
                
                if (algo_choice == 1) {
                    bubble_sort(arr, size);
                } else if (algo_choice == 2) {
                    selection_sort(arr, size);
                } else {
                    printf("Invalid choice!\n");
                    break;
                }
                
                printf("\nFinal sorted array: ");
                print_array(arr, size);
                print_stats();
                break;
            }
            
            case 2: {
                // Linked list demo
                printf("\n=== Linked List Sorting Demo ===\n");
                Node* head = create_sample_list();
                
                printf("Original list: ");
                print_list(head);
                
                reset_counters();
                bubble_sort_list(&head);
                
                printf("\nFinal sorted list: ");
                print_list(head);
                print_stats();
                
                free_list(head);
                break;
            }
            
            case 3:
                printf("Thank you for using the sorting demo!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
                break;
        }
    }
    
    return 0;
}
