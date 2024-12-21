// https://leetcode.com/problems/two-sum/ (Easy)

/**
 * The One Pass Hash Table algorithm iterates through the array once, storing each number's value and its index in a hash table.
 * For each element, it checks if the complement (target - current number) exists in the hash table.
 * If it does, the solution is found immediately. This approach ensures that each element is processed only once, achieving an optimal time complexity.
 */

#include <stdlib.h>
#include <stdio.h>

// Define the maximum size for the hash table
#define TABLE_SIZE 10000

// Structure to represent a key-value pair in the hash table
typedef struct {
    int key;
    int value;
} HashPair;

// Structure for the hash table
typedef struct {
    HashPair* pairs;
} HashTable;

// Function to create a new hash table
HashTable* createHashTable() {
    HashTable* table = malloc(sizeof(HashTable));
    table->pairs = malloc(TABLE_SIZE * sizeof(HashPair));
    for(int i = 0; i < TABLE_SIZE; i++) {
        table->pairs[i].key = 0;
        table->pairs[i].value = -1;
    }
    return table;
}

// Simple hash function
int hashFunction(int key) {
    return abs(key) % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insertHashTable(HashTable* table, int key, int value) {
    int index = hashFunction(key);
    table->pairs[index].key = key;
    table->pairs[index].value = value;
}

// Function to search for a key in the hash table
int searchHashTable(HashTable* table, int key) {
    int index = hashFunction(key);
    if(table->pairs[index].key == key) {
        return table->pairs[index].value;
    }
    return -1;
}

// Function to free the hash table
void freeHashTable(HashTable* table) {
    free(table->pairs);
    free(table);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Initialize the hash table
    HashTable* hashTable = createHashTable();

    // Allocate memory for the result
    int* result = malloc(2 * sizeof(int));

    // Iterate through the array
    for(int i = 0; i < numsSize; i++) {
        // Calculate the complement
        int complement = target - nums[i];
        
        // Search for the complement in the hash table
        int foundIndex = searchHashTable(hashTable, complement);
        if(foundIndex != -1) {
            // If found, set the result indices
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            // Free the hash table before returning
            freeHashTable(hashTable);
            return result;
        }
        
        // Insert the current number and its index into the hash table
        insertHashTable(hashTable, nums[i], i);
    }
    
    // If no solution is found, set return size to 0 and free the hash table
    *returnSize = 0;
    freeHashTable(hashTable);
    return result;
}

/**
 *Time Complexity
 * O(n)
 *
 * The algorithm processes each of the n elements in the input array exactly once. 
 * For each element, it performs constant-time operations such as calculating the complement, searching the hash table, and inserting into the hash table. 
 * Therefore, the overall time complexity scales linearly with the size of the input.
 *
 * Space Complexity
 * O(n)
 *
 * The hash table potentially stores each of the n elements from the input array, resulting in linear space usage relative to the number of input elements. 
 * Additionally, the result array uses constant space, but the dominant factor is the hash table, which requires space proportional to the input size.
 */