/**
 * @file array_sorting.c
 * @brief Implementation of sorting algorithms for integer arrays
 * @author Professional C Developer
 * @date 2024
 */

#include "sorting_algorithms.h"

/**
 * @brief Generate a random array of integers
 * @param arr Array to fill with random values
 * @param size Size of the array
 * @param max_value Maximum value for random numbers
 */
void generate_random_array(int arr[], int size, int max_value) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max_value;
    }
}

/**
 * @brief Selection Sort Algorithm
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * @param arr Array to sort
 * @param size Size of the array
 */
void selection_sort(int arr[], int size) {
    printf("\n=== Selection Sort ===\n");
    
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        
        // Find the minimum element in the remaining array
        for (int j = i + 1; j < size; j++) {
            comparison_count++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        // Swap if necessary
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            permutation_count++;
        }
        
        printf("Iteration %d: ", i + 1);
        display_array(arr, size);
    }
}

/**
 * @brief Bubble Sort Algorithm with early termination
 * Time Complexity: O(n²) worst case, O(n) best case
 * Space Complexity: O(1)
 * @param arr Array to sort
 * @param size Size of the array
 */
void bubble_sort(int arr[], int size) {
    printf("\n=== Bubble Sort ===\n");
    
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < size - i - 1; j++) {
            comparison_count++;
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                permutation_count++;
                swapped = true;
            }
        }
        
        printf("Iteration %d: ", i + 1);
        display_array(arr, size);
        
        // Early termination if no swaps occurred
        if (!swapped) {
            printf("Array is already sorted. Terminating early.\n");
            break;
        }
    }
}

/**
 * @brief Insertion Sort Algorithm
 * Time Complexity: O(n²) worst case, O(n) best case
 * Space Complexity: O(1)
 * @param arr Array to sort
 * @param size Size of the array
 */
void insertion_sort(int arr[], int size) {
    printf("\n=== Insertion Sort ===\n");
    
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0) {
            comparison_count++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                permutation_count++;
                j--;
            } else {
                break;
            }
        }
        
        arr[j + 1] = key;
        
        printf("Iteration %d: ", i);
        display_array(arr, size);
    }
}

/**
 * @brief Partition function for Quick Sort
 * @param arr Array to partition
 * @param low Starting index
 * @param high Ending index
 * @return Index of the pivot element
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        comparison_count++;
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            permutation_count++;
        }
    }
    
    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    permutation_count++;
    
    return (i + 1);
}

/**
 * @brief Quick Sort Algorithm
 * Time Complexity: O(n log n) average, O(n²) worst case
 * Space Complexity: O(log n)
 * @param arr Array to sort
 * @param low Starting index
 * @param high Ending index
 */
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        printf("After partitioning (pivot at index %d): ", pi);
        display_array(arr, high + 1);
        
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/**
 * @brief Merge function for Merge Sort
 * @param arr Array to merge
 * @param left Left boundary
 * @param mid Middle index
 * @param right Right boundary
 */
void merge_arrays(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int* left_arr = malloc(n1 * sizeof(int));
    int* right_arr = malloc(n2 * sizeof(int));
    
    if (!left_arr || !right_arr) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        comparison_count++;
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        permutation_count++;
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
        permutation_count++;
    }
    
    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
        permutation_count++;
    }
    
    printf("After merging: ");
    display_array(arr, right + 1);
    
    free(left_arr);
    free(right_arr);
}

/**
 * @brief Merge Sort Algorithm
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 * @param arr Array to sort
 * @param left Left boundary
 * @param right Right boundary
 */
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge_arrays(arr, left, mid, right);
    }
}

/**
 * @brief Comb Sort Algorithm
 * Time Complexity: O(n²) worst case, O(n log n) average
 * Space Complexity: O(1)
 * @param arr Array to sort
 * @param size Size of the array
 */
void comb_sort(int arr[], int size) {
    printf("\n=== Comb Sort ===\n");
    
    int gap = size;
    bool swapped = true;
    
    while (gap != 1 || swapped) {
        // Update gap value
        gap = (gap * 10) / 13;
        if (gap < 1) {
            gap = 1;
        }
        
        swapped = false;
        
        for (int i = 0; i < size - gap; i++) {
            comparison_count++;
            if (arr[i] > arr[i + gap]) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                permutation_count++;
                swapped = true;
            }
        }
        
        printf("Gap %d: ", gap);
        display_array(arr, size);
    }
}
