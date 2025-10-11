/**
 * @file utils.c
 * @brief Utility functions for sorting algorithms
 * @author Professional C Developer
 * @date 2024
 */

#include "sorting_algorithms.h"

/* Global performance counters */
unsigned long long comparison_count = 0;
unsigned long long permutation_count = 0;

/**
 * @brief Reset performance counters
 */
void reset_counters(void) {
    comparison_count = 0;
    permutation_count = 0;
}

/**
 * @brief Print performance statistics
 */
void print_statistics(void) {
    printf("\n=== Performance Statistics ===\n");
    printf("Total comparisons: %llu\n", comparison_count);
    printf("Total permutations: %llu\n", permutation_count);
    printf("=============================\n");
}

/**
 * @brief Display array elements
 * @param arr Array to display
 * @param size Size of the array
 */
void display_array(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Display matrix rows
 * @param matrix Matrix to display
 * @param rows Number of rows to display
 */
void display_matrix(const char matrix[MAX_ROWS][MAX_COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("%s\n", matrix[i]);
    }
    printf("\n");
}

/**
 * @brief Display linked list elements
 * @param head Head of the linked list
 */
void display_linked_list(const Node* head) {
    const Node* current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

/**
 * @brief Get user input with validation
 * @param min Minimum allowed value
 * @param max Maximum allowed value
 * @param prompt Prompt message to display
 * @return Valid user choice
 */
int get_user_choice(int min, int max, const char* prompt) {
    int choice;
    
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &choice) == 1) {
            if (choice >= min && choice <= max) {
                break;
            } else {
                printf("Invalid input! Please enter a number between %d and %d.\n", min, max);
            }
        } else {
            printf("Invalid input! Please enter a valid number.\n");
            // Clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    
    return choice;
}

/**
 * @brief Print main menu
 */
void print_menu(void) {
    printf("\n=== Sorting Algorithms Demonstration ===\n");
    printf("Choose a data structure to test:\n");
    printf("1. Array Sorting\n");
    printf("2. Linked List Sorting\n");
    printf("3. Matrix Sorting\n");
    printf("4. Exit\n");
    printf("==========================================\n");
}
