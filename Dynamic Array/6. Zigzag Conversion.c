// https://leetcode.com/problems/zigzag-conversion (Medium)

/**
 * Explanation of Direct Simulation with Row Assignment: This algorithm simulates writing the input string in a zigzag pattern across the specified number of rows by assigning each character to the appropriate row sequentially, alternating direction when reaching the top or bottom row. 
 * After all characters are assigned to their respective rows, the rows are concatenated to form the final converted string.
 */

#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    
    if (numRows == 1) {
        
        return s;
    }

    int length = 0;
    
    while (s[length] != '\0') {
        length++;
    }

    // Allocate memory for each row
    char** rows = (char**)malloc(numRows * sizeof(char*));
    
    if (rows == NULL) {
        
        return NULL;
    }

    for (int i = 0; i < numRows; i++) {
        
        rows[i] = (char*)malloc((length + 1) * sizeof(char));
        
        if (rows[i] == NULL) {
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(rows[j]);
            }
            free(rows);
            
            return NULL;
        }
        rows[i][0] = '\0';
    }

    int currentRow = 0;
    
    int direction = -1;

    for (int i = 0; i < length; i++) {
        
        int rowLength = 0;
        while (rows[currentRow][rowLength] != '\0') {
            rowLength++;
        }
        rows[currentRow][rowLength] = s[i];
        rowLength++;
        rows[currentRow][rowLength] = '\0';

        // Change direction if at first or last row
        if (currentRow == 0 || currentRow == numRows - 1) {
            direction = -direction;
        }
        currentRow += direction;
    }

    // Calculate total length for the result
    int totalLength = 0;
    for (int i = 0; i < numRows; i++) {
        int rowLen = 0;
        while (rows[i][rowLen] != '\0') {
            rowLen++;
        }
        totalLength += rowLen;
    }

    // Allocate memory for the result string
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    
    if (result == NULL) {
        // Free all rows if allocation fails
        for (int i = 0; i < numRows; i++) {
            free(rows[i]);
        }
        free(rows);
        
        return NULL;
    }

    result[0] = '\0';
    
    // Concatenate all rows into the result
    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
    }

    // Free memory allocated for rows
    for (int i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);
    
    return result;
}

/**
 * Time Complexity
 * O(n * numRows)
 *
 * The algorithm iterates through each character of the input string once (O(n)). 
 * For each character, it appends to the corresponding row, which can take up to O(1) time on average. 
 * However, the concatenation step at the end involves traversing all rows, resulting in an overall time complexity proportional to n * numRows.
 *
 * Space Complexity
 * O(n + numRows)
 *
 * The algorithm uses additional memory to store each row separately, requiring O(n) space for all characters. 
 * Additionally, it allocates space for managing the row pointers, which takes O(numRows) space. 
 * Therefore, the total space complexity is O(n + numRows).
 */