// https://leetcode.com/problems/palindrome-number (Easy)

/**
 * The Recursive Digit Comparison algorithm works by comparing the first and last digits of the integer.
 * If they are equal, the algorithm removes these digits and recursively checks the remaining number.
 * This process continues until all digits are successfully compared, confirming the number is a palindrome.
 */

#include <stdbool.h>

bool helper(int num, int divisor) {
    
    // Base case: when there's only one digit left
    if (num == 0) {
        return true;
    }
    
    // Extract the leading digit
    int leadingDigit = num / divisor;
    
    // Extract the trailing digit
    int trailingDigit = num % 10;
    
    // If the leading and trailing digits do not match, it's not a palindrome
    if (leadingDigit != trailingDigit) {
        return false;
    }
    
    // Remove the leading and trailing digits from the number
    num = (num % divisor) / 10;
    
    // Adjust the divisor by two digits
    divisor /= 100;
    
    // Recursive call for the reduced number
    return helper(num, divisor);
}

bool isPalindrome(int x) {
    
    // If the number is negative, it cannot be a palindrome
    if (x < 0) {
        return false;
    }
    
    // Calculate the divisor to extract the first digit
    int divisor = 1;
    while (x / divisor >= 10) {
        divisor *= 10;
    }
    
    // Call the helper function with the initial number and divisor
    return helper(x, divisor);
}

/**
 * Time Complexity
 * The algorithm operates in O(log n) time, where n is the integer being checked. 
 * This efficiency arises because the number of digits d in n is proportional to log n (since each digit represents a power of 10). 
 * In each recursive call, two digits are processed (the first and last), leading to a total of d/2 recursive calls, which simplifies to O(log n).

 * Space Complexity
 * The space complexity is O(log n) due to the recursion stack. 
 * Each recursive call consumes constant space, and since there are O(log n) recursive calls (one for every two digits), the total space used grows logarithmically with the size of the input number n.
 */