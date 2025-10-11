/**
 * @file list_sorting.c
 * @brief Implementation of sorting algorithms for linked lists
 * @author Professional C Developer
 * @date 2024
 */

#include "sorting_algorithms.h"

/**
 * @brief Create a new node with the given word
 * @param word String to store in the node
 * @return Pointer to the new node, or NULL if allocation fails
 */
Node* create_node(const char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed for new node!\n");
        return NULL;
    }
    
    strncpy(new_node->word, word, MAX_WORD_LENGTH - 1);
    new_node->word[MAX_WORD_LENGTH - 1] = '\0'; // Ensure null termination
    new_node->next = NULL;
    
    return new_node;
}

/**
 * @brief Insert a new node at the end of the linked list
 * @param head Pointer to the head of the list
 * @param word Word to insert
 */
void insert_end(Node** head, const char* word) {
    Node* new_node = create_node(word);
    if (new_node == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

/**
 * @brief Free all nodes in the linked list
 * @param head Pointer to the head of the list
 */
void free_linked_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

/**
 * @brief Create a linked list from an array of words
 * @param words Array of strings
 * @param count Number of words in the array
 * @return Pointer to the head of the created list
 */
Node* create_linked_list_from_words(const char* words[], int count) {
    Node* head = NULL;
    
    for (int i = 0; i < count; i++) {
        insert_end(&head, words[i]);
    }
    
    return head;
}

/**
 * @brief Insertion Sort for Linked List
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * @param head Pointer to the head of the linked list
 */
void insertion_sort_linked_list(Node** head) {
    printf("\n=== Insertion Sort for Linked List ===\n");
    
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    
    Node* sorted = NULL;
    Node* current = *head;
    
    while (current != NULL) {
        Node* next = current->next;
        
        // Insert current node into sorted list
        if (sorted == NULL || strcmp(sorted->word, current->word) >= 0) {
            current->next = sorted;
            sorted = current;
            permutation_count++;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && strcmp(temp->next->word, current->word) < 0) {
                comparison_count++;
                temp = temp->next;
            }
            comparison_count++;
            
            current->next = temp->next;
            temp->next = current;
            permutation_count++;
        }
        
        printf("After inserting '%s': ", current->word);
        display_linked_list(sorted);
        current = next;
    }
    
    *head = sorted;
}

/**
 * @brief Bubble Sort for Linked List
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 * @param head Pointer to the head of the linked list
 */
void bubble_sort_linked_list(Node** head) {
    printf("\n=== Bubble Sort for Linked List ===\n");
    
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    
    bool swapped;
    Node* ptr1;
    Node* last_ptr = NULL;
    
    do {
        swapped = false;
        ptr1 = *head;
        
        while (ptr1->next != last_ptr) {
            comparison_count++;
            if (strcmp(ptr1->word, ptr1->next->word) > 0) {
                // Swap words
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, ptr1->word);
                strcpy(ptr1->word, ptr1->next->word);
                strcpy(ptr1->next->word, temp);
                
                swapped = true;
                permutation_count++;
            }
            ptr1 = ptr1->next;
        }
        
        last_ptr = ptr1;
        printf("After iteration: ");
        display_linked_list(*head);
        
    } while (swapped);
}
