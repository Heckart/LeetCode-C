// https://leetcode.com/problems/longest-palindromic-substring (Medium)

/**
 * Manacher's Algorithm is used to find the longest palindromic substring in linear time by transforming the original string to handle even-length palindromes. 
 * The algorithm iteratively expands around each center to determine the maximum palindrome radius, maintaining a center and right boundary to optimize the search. 
 * This solution implements Manacher's Algorithm by preprocessing the string, maintaining an array of palindrome radii, and identifying the longest palindromic substring based on these radii.
 */

char* longestPalindrome(char* s) {
    // https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm
    
    // Check for NULL input
    if (s == NULL) return "";
    
    // Get the length of the string
    int stringLength = strlen(s);
    
    // If the string is empty, return an empty string
    if (stringLength == 0) return "";
    
    // Preprocess the string by inserting '#' between each character and adding boundary characters
    int transformedLength = 2 * stringLength + 3;
    char *transformedString = (char *)malloc(sizeof(char) * transformedLength);
    
    // Initialize the transformed string with boundary characters
    transformedString[0] = '^';
    for (int i = 0; i < stringLength; i++) {
        
        transformedString[2 * i + 1] = '#';
        transformedString[2 * i + 2] = s[i];
    }
    transformedString[2 * stringLength + 1] = '#';
    transformedString[2 * stringLength + 2] = '$';
    
    // Allocate memory for the palindrome radii array
    int *palindromeRadii = (int *)malloc(sizeof(int) * transformedLength);
    
    // Initialize the center and right boundary of the current palindrome
    int center = 0;
    int rightBoundary = 0;
    
    // Iterate through the transformed string to populate palindrome radii
    for (int i = 1; i < transformedLength - 1; i++) {
        
        // Calculate the mirror position of the current index
        int mirrorIndex = 2 * center - i;
        
        // Initialize palindrome radius for the current position
        if (i < rightBoundary) {
            palindromeRadii[i] = (palindromeRadii[mirrorIndex] < (rightBoundary - i)) ? palindromeRadii[mirrorIndex] : (rightBoundary - i);
        } else {
            palindromeRadii[i] = 0;
        }
        
        // Expand the palindrome centered at the current index
        while (transformedString[i + (1 + palindromeRadii[i])] == transformedString[i - (1 + palindromeRadii[i])]) {
            palindromeRadii[i]++;
        }
        
        // Update the center and right boundary if the expanded palindrome goes beyond the current right boundary
        if (i + palindromeRadii[i] > rightBoundary) {
            center = i;
            rightBoundary = i + palindromeRadii[i];
        }
    }
    
    // Find the maximum palindrome radius and its center index
    int maxRadius = 0;
    int maxCenter = 0;
    for (int i = 1; i < transformedLength - 1; i++) {
        if (palindromeRadii[i] > maxRadius) {
            maxRadius = palindromeRadii[i];
            maxCenter = i;
        }
    }
    
    // Calculate the starting index of the longest palindrome in the original string
    int startIndex = (maxCenter - maxRadius) / 2;
    
    // Allocate memory for the result substring
    char *result = (char *)malloc(sizeof(char) * (maxRadius + 1));
    
    // Copy the longest palindromic substring into the result
    strncpy(result, s + startIndex, maxRadius);
    
    // Null-terminate the result string
    result[maxRadius] = '\0';
    
    // Free the allocated memory for transformed string and palindrome radii
    free(transformedString);
    free(palindromeRadii);
    
    // Return the longest palindromic substring
    return result;
}

/**
 * Time Complexity
 * O(n)
 *
 * Manacher's Algorithm processes the input string in linear time. 
 * The preprocessing step transforms the original string by inserting special characters, which takes O(n) time. 
 * The main loop iterates through each character of the transformed string once, performing constant-time operations for each iteration. 
 * As a result, the overall time complexity is linear with respect to the length of the input string.
 *
 * Space Complexity
 * O(n)
 *
 * The algorithm requires additional space proportional to the size of the input string. Specifically:
 * The transformed string has a length of 2n + 3, where n is the length of the original string.
 * The palindromeRadii array stores an integer for each character in the transformed string, resulting in O(n) space.
 * Additional space is used for variables and the resulting substring, but these contributions are also linear. 
 * Therefore, the overall space complexity is linear with respect to the length of the input string. 
 */