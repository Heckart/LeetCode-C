// https://leetcode.com/problems/container-with-most-water (Medium)

/**
 * The Two Pointers algorithm is used by initializing one pointer at the beginning and one at the end of the array.
 * We calculate the area formed by the lines at these pointers and move the pointer pointing to the shorter line towards the center to find a potentially larger area.
 */

int maxArea(int* height, int heightSize) {
    
    // Initialize left and right pointers
    int left = 0;
    int right = heightSize - 1;
    
    // Variable to store the maximum area found
    int maxArea = 0;
    
    // Loop until the two pointers meet
    while (left < right) {
        
        // Calculate the current area
        int width = right - left;
        int currentHeight = height[left] < height[right] ? height[left] : height[right];
        int currentArea = width * currentHeight;
        
        // Update maxArea if currentArea is larger
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }
        
        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    // Return the maximum area found
    return maxArea;
}

/**
 * Time Complexity
 * The time complexity is O(n), where n is the number of elements in the height array. 
 * The algorithm employs the Two Pointers technique by initializing one pointer at the start (left) and another at the end (right) of the array. 
 * In each iteration of the while loop, one of the pointers moves closer to the center. 
 * Since each pointer moves at most n steps and the loop runs until the two pointers meet, the total number of operations scales linearly with the size of the input array.
 *
 * Space Complexity
 * The space complexity is O(1). 
 * The algorithm uses a constant amount of extra space regardless of the input size. 
 * It maintains a fixed number of integer variables (left, right, maxArea, width, currentHeight, and currentArea) to compute and store intermediate results. 
 * No additional space is required that scales with the input size.
 *
 * Explanation
 * The Two Pointers algorithm efficiently solves the problem by reducing the search space from both ends of the array towards the center. 
 * By always moving the pointer pointing to the shorter line, it ensures that the height constraint is optimally managed to potentially find a larger area. 
 * This strategy guarantees that all possible pairs of lines that could form a larger area are considered in a single pass, thus achieving linear time complexity while using minimal extra space.
 */