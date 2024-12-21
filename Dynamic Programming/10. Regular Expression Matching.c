// https://leetcode.com/problems/regular-expression-matching (Hard)

/**
 * Iterative Dynamic Programming approach is used to solve the regular expression matching problem.
 * A DP table is constructed where dp[i][j] represents whether the first i characters of the string s match the first j characters of the pattern p. 
 * The table is filled iteratively based on the pattern rules, handling '.' and '*' accordingly to cover all possible matching scenarios.
 */

bool isMatch(char* s, char* p) {
    int stringLength = strlen(s);
    int patternLength = strlen(p);
    
    // Allocate DP table
    bool dp[stringLength + 1][patternLength + 1];
    
    // Initialize DP table to false
    memset(dp, false, sizeof(dp));
    
    // Empty string and empty pattern match
    dp[0][0] = true;
    
    // Initialize first row for patterns like a*, a*b*, a*b*c*
    for(int col = 1; col <= patternLength; col++) {
        if(p[col - 1] == '*') {
            dp[0][col] = dp[0][col - 2];
        }
    }
    
    // Fill the DP table
    for(int row = 1; row <= stringLength; row++) {
        for(int col = 1; col <= patternLength; col++) {
            if(p[col - 1] == '.' || p[col - 1] == s[row - 1]) {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else if(p[col - 1] == '*') {
                // Consider zero occurrence of the character before '*'
                dp[row][col] = dp[row][col - 2];
                
                // If character before '*' matches current character in s
                if(p[col - 2] == '.' || p[col - 2] == s[row - 1]) {
                    dp[row][col] = dp[row][col] || dp[row - 1][col];
                }
            }
            else {
                dp[row][col] = false;
            }
        }
    }
    
    // Return the result
    return dp[stringLength][patternLength];
}

/**
 * Time Complexity
 * O(n * m)
 *
 * Where:
 * n is the length of the input string s.
 * m is the length of the pattern p.
 *
 * The algorithm fills a DP table of size (n + 1) x (m + 1). 
 * It uses two nested loops, each iterating up to n and m respectively, resulting in a time complexity proportional to the product of the two lengths.
 *
 * Space Complexity
 * O(n * m)
 *
 * The algorithm utilizes a two-dimensional DP table with dimensions (n + 1) x (m + 1) to store intermediate matching results. 
 * This requires space proportional to the product of the lengths of the input string and the pattern.
 */