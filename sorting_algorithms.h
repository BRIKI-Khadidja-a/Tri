/**
 * @file sorting_algorithms.h
 * @brief Header file for sorting algorithms implementation
 * @author Professional C Developer
 * @date 2024
 * 
 * This file contains declarations for various sorting algorithms
 * implemented for arrays, linked lists, and matrices.
 */

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/* Constants */
#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_WORD_LENGTH 100
#define MAX_STRING_LENGTH 256

/* Performance counters */
extern unsigned long long comparison_count;
extern unsigned long long permutation_count;

/* Data structures */

/**
 * @brief Node structure for linked list implementation
 */
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

/* Function prototypes */

/* Utility functions */
void reset_counters(void);
void print_statistics(void);
void generate_random_array(int arr[], int size, int max_value);
void generate_random_matrix(char matrix[MAX_ROWS][MAX_COLS]);
Node* create_linked_list_from_words(const char* words[], int count);

/* Display functions */
void display_array(const int arr[], int size);
void display_matrix(const char matrix[MAX_ROWS][MAX_COLS], int rows);
void display_linked_list(const Node* head);

/* Array sorting algorithms */
void selection_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void quick_sort(int arr[], int low, int high);
void merge_sort(int arr[], int left, int right);
void comb_sort(int arr[], int size);

/* Linked list sorting algorithms */
void insertion_sort_linked_list(Node** head);
void bubble_sort_linked_list(Node** head);

/* Matrix sorting algorithms */
void bubble_sort_matrix(char matrix[MAX_ROWS][MAX_COLS], int rows);
void merge_sort_matrix(char matrix[MAX_ROWS][MAX_COLS], int left, int right);

/* Helper functions */
int partition(int arr[], int low, int high);
void merge_arrays(int arr[], int left, int mid, int right);
void merge_matrices(char matrix[MAX_ROWS][MAX_COLS], int left, int mid, int right);
Node* create_node(const char* word);
void insert_end(Node** head, const char* word);
void free_linked_list(Node* head);

/* User interface functions */
void run_array_sorting_demo(void);
void run_linked_list_sorting_demo(void);
void run_matrix_sorting_demo(void);
int get_user_choice(int min, int max, const char* prompt);
void print_menu(void);

#endif /* SORTING_ALGORITHMS_H */
