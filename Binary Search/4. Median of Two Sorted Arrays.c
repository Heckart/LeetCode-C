// https://leetcode.com/problems/median-of-two-sorted-arrays/description/ (Hard)

/**
 * Explanation of Binary Search Partition algorithm: The algorithm performs a binary search on the smaller array to find a partition where the combined left halves from both arrays contain the median. 
 * It ensures that every element on the left side is less than or equal to every element on the right side by adjusting the partition based on comparisons.
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    // Ensure nums1 is the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    // Initialize binary search boundaries
    int imin = 0;
    int imax = nums1Size;
    int halfLen = (nums1Size + nums2Size + 1) / 2;
    
    while (imin <= imax) {
        
        // Partition nums1
        int i = (imin + imax) / 2;
        
        // Partition nums2
        int j = halfLen - i;

        // If i is too small, must increase it
        if (i < nums1Size && nums2[j - 1] > nums1[i]) {
            imin = i + 1;
        }
        // If i is too big, must decrease it
        else if (i > 0 && nums1[i - 1] > nums2[j]) {
            imax = i - 1;
        }
        else {
            // i is perfect
            
            int maxLeft;
            if (i == 0) {
                maxLeft = nums2[j - 1];
            }
            else if (j == 0) {
                maxLeft = nums1[i - 1];
            }
            else {
                maxLeft = (nums1[i - 1] > nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];
            }

            // Check if total length is odd
            if ((nums1Size + nums2Size) % 2 == 1) {
                return maxLeft;
            }

            int minRight;
            if (i == nums1Size) {
                minRight = nums2[j];
            }
            else if (j == nums2Size) {
                minRight = nums1[i];
            }
            else {
                minRight = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
            }

            // Calculate median
            return (maxLeft + minRight) / 2.0;
        }
    }

    return 0.0;
}

/**
 * Time Complexity
 * O(log(min(n, m))
 *
 * The algorithm performs a binary search on the smaller of the two input arrays. 
 * In each step, it halves the search space, leading to a logarithmic time complexity relative to the size of the smaller array (n or m).
 *
 * Space Complexity
 * O(1)
 *
 * The algorithm uses a constant amount of extra space. 
 * It only stores a few integer variables for indices and calculations, regardless of the input size.
 */