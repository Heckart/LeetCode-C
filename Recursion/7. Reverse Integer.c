// https://leetcode.com/problems/reverse-integer/ (Medium)

/**
 * Explanation: This solution uses a recursive method to reverse the digits of the integer.
 * At each recursive call, the last digit of the current number is extracted and appended to the reversed number.
 * The recursion continues until all digits have been processed. 
 * Overflow checks are performed to ensure the reversed number remains within the 32-bit signed integer range.
 */

#include <limits.h>

// Helper function to perform recursion
int reverseHelper(int original, int reversed) {
    // Base case: if original is 0, return reversed
    if (original == 0) {
        return reversed;
    }
    // Get the last digit
    int lastDigit = original % 10;
    // Check for overflow before updating reversed
    if (reversed > INT32_MAX / 10 || (reversed == INT32_MAX / 10 && lastDigit > 7)) {
        return 0;
    }
    if (reversed < INT32_MIN / 10 || (reversed == INT32_MIN / 10 && lastDigit < -8)) {
        return 0;
    }
    // Update the reversed number with the last digit
    int newReversed = reversed * 10 + lastDigit;
    // Recursive call with the remaining number
    return reverseHelper(original / 10, newReversed);
}

int reverse(int x){
    // Start the recursion with reversed number as 0
    return reverseHelper(x, 0);
}

/**
 * Time Complexity
 * O(n)
 *
 * The algorithm processes each digit of the input integer once through recursive calls, resulting in linear time complexity relative to the number of digits.
 *
 * Space Complexity
 * O(n)
 *
 * Each recursive call adds a layer to the call stack, with the number of layers proportional to the number of digits in the input integer.
 *
 * Explanation
 * Time Complexity: The function makes one recursive call per digit of the integer. 
 * If the integer has n digits, the function will be called n times, leading to a time complexity of O(n).
 *
 * Space Complexity: The recursive approach uses the call stack to keep track of recursive calls.
 * For an integer with n digits, there will be n recursive calls on the stack simultaneously, resulting in a space complexity of O(n).
 */