/**
 * @file matrix_sorting.c
 * @brief Implementation of sorting algorithms for string matrices
 * @author Professional C Developer
 * @date 2024
 */

#include "sorting_algorithms.h"

/**
 * @brief Generate a random matrix of strings
 * @param matrix Matrix to fill with random strings
 */
void generate_random_matrix(char matrix[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS - 1; j++) {
            matrix[i][j] = 'a' + rand() % 26; // Random lowercase letters
        }
        matrix[i][MAX_COLS - 1] = '\0'; // Null terminate
    }
}

/**
 * @brief Merge function for matrix merge sort
 * @param matrix Matrix to merge
 * @param left Left boundary
 * @param mid Middle index
 * @param right Right boundary
 */
void merge_matrices(char matrix[MAX_ROWS][MAX_COLS], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary matrices
    char left_matrix[n1][MAX_COLS];
    char right_matrix[n2][MAX_COLS];
    
    // Copy data to temporary matrices
    for (int i = 0; i < n1; i++) {
        strcpy(left_matrix[i], matrix[left + i]);
    }
    for (int j = 0; j < n2; j++) {
        strcpy(right_matrix[j], matrix[mid + 1 + j]);
    }
    
    // Merge the temporary matrices back
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        comparison_count++;
        if (strcmp(left_matrix[i], right_matrix[j]) <= 0) {
            strcpy(matrix[k], left_matrix[i]);
            i++;
        } else {
            strcpy(matrix[k], right_matrix[j]);
            j++;
        }
        permutation_count++;
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        strcpy(matrix[k], left_matrix[i]);
        i++;
        k++;
        permutation_count++;
    }
    
    while (j < n2) {
        strcpy(matrix[k], right_matrix[j]);
        j++;
        k++;
        permutation_count++;
    }
}

/**
 * @brief Bubble Sort for Matrix
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * @param matrix Matrix to sort
 * @param rows Number of rows in the matrix
 */
void bubble_sort_matrix(char matrix[MAX_ROWS][MAX_COLS], int rows) {
    printf("\n=== Bubble Sort for Matrix ===\n");
    
    for (int i = 0; i < rows - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < rows - i - 1; j++) {
            comparison_count++;
            if (strcmp(matrix[j], matrix[j + 1]) > 0) {
                // Swap rows
                char temp[MAX_COLS];
                strcpy(temp, matrix[j]);
                strcpy(matrix[j], matrix[j + 1]);
                strcpy(matrix[j + 1], temp);
                
                swapped = true;
                permutation_count++;
            }
        }
        
        printf("After iteration %d:\n", i + 1);
        display_matrix(matrix, rows);
        
        // Early termination if no swaps occurred
        if (!swapped) {
            printf("Matrix is already sorted. Terminating early.\n");
            break;
        }
    }
}

/**
 * @brief Merge Sort for Matrix
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * @param matrix Matrix to sort
 * @param left Left boundary
 * @param right Right boundary
 */
void merge_sort_matrix(char matrix[MAX_ROWS][MAX_COLS], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort_matrix(matrix, left, mid);
        merge_sort_matrix(matrix, mid + 1, right);
        merge_matrices(matrix, left, mid, right);
        
        printf("After merging subarrays [%d-%d] and [%d-%d]:\n", 
               left, mid, mid + 1, right);
        display_matrix(matrix, right + 1);
    }
}
