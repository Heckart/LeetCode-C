// https://leetcode.com/problems/string-to-integer-atoi (Medium)

/**
 * The Single-Pass Iterative Parsing algorithm processes the input string one character at a time in a single pass.
 * It systematically handles whitespace, sign determination, digit conversion, and overflow while parsing the string, ensuring optimal performance.
 */

int myAtoi(char* s) {
    int index = 0;
    int sign = 1;
    long result = 0;

    // Skip leading whitespaces
    while (s[index] == ' ') {
        index++;
    }

    // Check for sign
    if (s[index] == '-' || s[index] == '+') {

        // Set sign accordingly
        if (s[index] == '-') {
            sign = -1;
        }
        index++;
    }

    // Convert digits to integer
    while (s[index] >= '0' && s[index] <= '9') {

        // Append current digit
        result = result * 10 + (s[index] - '0');

        // Check for overflow
        if (sign * result <= (long)INT32_MIN) {
            return INT32_MIN;
        }
        if (sign * result >= (long)INT32_MAX) {
            return INT32_MAX;
        }
        index++;
    }

    // Apply sign to result
    result = result * sign;

    return (int)result;
}

/**
 * Time Complexity
 * O(n)
 *
 * The algorithm processes each character of the input string exactly once in a single pass, where n is the length of the string. This results in linear time complexity.
 *
 * Space Complexity
 * O(1)
 *
 * The algorithm uses a constant amount of extra space for variables such as index, sign, and result, regardless of the input size.
 *
 * Explanation
 * Time Complexity:
 * The function iterates through the input string one character at a time with loops that skip whitespaces, determine the sign, and convert digits to an integer. 
 * Each of these operations traverses the string once without nested iterations, leading to a linear time complexity proportional to the length of the input string (O(n)).
 *
 * Space Complexity:
 * The function utilizes a fixed number of variables (index, sign, result) to store intermediate states and the final result. 
 * The space required does not grow with the size of the input string, maintaining constant space complexity (O(1)).
 */