// https://leetcode.com/problems/longest-substring-without-repeating-characters (Medium)

/**
 * The Sliding Window with Hash Map algorithm maintains a window of unique characters by keeping track of the last index of each character using a hash map. 
 * As we iterate through the string, if a character is repeated within the current window, the window is adjusted to exclude the previous occurrence.
 * This approach efficiently finds the longest substring without repeating characters.
 */

int lengthOfLongestSubstring(char* s) {
    
    // Define a hash map to store the last index of each character
    int charIndex[256];
    
    // Initialize all entries to -1
    for(int i = 0; i < 256; i++) {
        charIndex[i] = -1;
    }
    
    // Initialize variables
    int maxLength = 0;
    int left = 0;
    
    // Iterate over each character
    for(int right = 0; s[right] != '\0'; right++) {
        
        // If the character is already in the current window
        if(charIndex[(unsigned char)s[right]] >= left) {
            
            // Move the left pointer to exclude the previous occurrence
            left = charIndex[(unsigned char)s[right]] + 1;
        }
        
        // Update the last index of the character
        charIndex[(unsigned char)s[right]] = right;
        
        // Update the maximum length
        if(right - left + 1 > maxLength) {
            maxLength = right - left + 1;
        }
    }
    
    return maxLength;
}

/**
 * Time Complexity
 * O(n)
 *
 * The algorithm processes each character in the string exactly once. 
 * The right pointer traverses the string from start to end, and the left pointer only moves forward. 
 * All operations inside the loop-hash map lookups, updates, and comparisons-are constant time. 
 * Therefore, the overall time complexity is linear with respect to the length of the string.
 * 
 * Space Complexity
 * O(1)
 *
 * The space used by the algorithm is constant. 
 * The hash map charIndex has a fixed size of 256 to accommodate all possible ASCII characters, regardless of the input string size. 
 * Additionally, only a few integer variables are used for tracking indices and the maximum length. 
 * Thus, the space complexity does not scale with the input size.
 */