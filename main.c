/**
 * @file main.c
 * @brief Main program for sorting algorithms demonstration
 * @author Professional C Developer
 * @date 2024
 */

#include "sorting_algorithms.h"

/**
 * @brief Run array sorting demonstration
 */
void run_array_sorting_demo(void) {
    printf("\n=== Array Sorting Demonstration ===\n");
    
    // Get array size
    int size = get_user_choice(5, 1000, 
        "Enter array size (5-1000): ");
    
    // Create and initialize array
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    generate_random_array(arr, size, 100);
    
    printf("\nArray before sorting: ");
    display_array(arr, size);
    
    // Get sorting algorithm choice
    printf("\nChoose sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Comb Sort\n");
    
    int choice = get_user_choice(1, 6, "Enter your choice: ");
    
    reset_counters();
    
    // Apply chosen algorithm
    switch (choice) {
        case 1:
            selection_sort(arr, size);
            break;
        case 2:
            bubble_sort(arr, size);
            break;
        case 3:
            insertion_sort(arr, size);
            break;
        case 4:
            printf("\n=== Quick Sort ===\n");
            quick_sort(arr, 0, size - 1);
            break;
        case 5:
            printf("\n=== Merge Sort ===\n");
            merge_sort(arr, 0, size - 1);
            break;
        case 6:
            comb_sort(arr, size);
            break;
    }
    
    printf("\nArray after sorting: ");
    display_array(arr, size);
    print_statistics();
    
    free(arr);
}

/**
 * @brief Run linked list sorting demonstration
 */
void run_linked_list_sorting_demo(void) {
    printf("\n=== Linked List Sorting Demonstration ===\n");
    
    // Create linked list with sample words
    const char* words[] = {"apple", "banana", "cherry", "date", "elderberry", 
                          "fig", "grape", "honeydew", "kiwi", "lemon"};
    int word_count = sizeof(words) / sizeof(words[0]);
    
    Node* head = create_linked_list_from_words(words, word_count);
    
    printf("Linked list before sorting: ");
    display_linked_list(head);
    
    // Get sorting algorithm choice
    printf("\nChoose sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Bubble Sort\n");
    
    int choice = get_user_choice(1, 2, "Enter your choice: ");
    
    reset_counters();
    
    // Apply chosen algorithm
    switch (choice) {
        case 1:
            insertion_sort_linked_list(&head);
            break;
        case 2:
            bubble_sort_linked_list(&head);
            break;
    }
    
    printf("\nLinked list after sorting: ");
    display_linked_list(head);
    print_statistics();
    
    free_linked_list(head);
}

/**
 * @brief Run matrix sorting demonstration
 */
void run_matrix_sorting_demo(void) {
    printf("\n=== Matrix Sorting Demonstration ===\n");
    
    // Create and initialize matrix
    char matrix[MAX_ROWS][MAX_COLS];
    generate_random_matrix(matrix);
    
    printf("Matrix before sorting:\n");
    display_matrix(matrix, MAX_ROWS);
    
    // Get sorting algorithm choice
    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");
    
    int choice = get_user_choice(1, 2, "Enter your choice: ");
    
    reset_counters();
    
    // Apply chosen algorithm
    switch (choice) {
        case 1:
            bubble_sort_matrix(matrix, MAX_ROWS);
            break;
        case 2:
            printf("\n=== Merge Sort for Matrix ===\n");
            merge_sort_matrix(matrix, 0, MAX_ROWS - 1);
            break;
    }
    
    printf("\nMatrix after sorting:\n");
    display_matrix(matrix, MAX_ROWS);
    print_statistics();
}

/**
 * @brief Main function
 * @return Exit status
 */
int main(void) {
    // Initialize random seed
    srand((unsigned int)time(NULL));
    
    printf("Welcome to the Professional Sorting Algorithms Demo!\n");
    printf("This program demonstrates various sorting algorithms\n");
    printf("with performance analysis and step-by-step visualization.\n");
    
    int choice;
    
    do {
        print_menu();
        choice = get_user_choice(1, 4, "Enter your choice: ");
        
        switch (choice) {
            case 1:
                run_array_sorting_demo();
                break;
            case 2:
                run_linked_list_sorting_demo();
                break;
            case 3:
                run_matrix_sorting_demo();
                break;
            case 4:
                printf("Thank you for using the sorting algorithms demo!\n");
                break;
        }
        
        if (choice != 4) {
            printf("\nPress Enter to continue...");
            getchar();
            getchar(); // Consume newline
        }
        
    } while (choice != 4);
    
    return 0;
}
