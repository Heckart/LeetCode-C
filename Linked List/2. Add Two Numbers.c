// https://leetcode.com/problems/add-two-numbers (Medium)

/**
 * Explanation of the iterative approach: We traverse both linked lists node by node, summing corresponding digits along with any carry from the previous addition. 
 * We create new nodes for the result list with the sum's digit, and handle any remaining carry after traversing both lists.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    // Initialize a dummy head to simplify result list construction
    struct ListNode dummy;
    
    // Current pointer to build the new list
    struct ListNode* current = &dummy;
    
    // Initialize carry to 0
    int carry = 0;
    
    // Iterate through lists until both are NULL and carry is 0
    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        // Get the current values from l1 and l2
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        
        // Calculate the sum and update carry
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        
        // Create a new node with the digit value
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        // Attach the new node to the result list
        current->next = newNode;
        current = current->next;
        
        // Move to the next nodes
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    // Return the next node of dummy, which is the head of the result list
    return dummy.next;
}

/**
 * Time Complexity
 * O(max(N, M))
 *
 * The algorithm traverses both linked lists once, where N and M are the lengths of the two lists. 
 * It processes each node exactly once, resulting in a linear time complexity relative to the length of the longer list.
 *
 * Space Complexity
 * O(max(N, M))
 *
 * A new linked list is created to store the result, which requires space proportional to the length of the longer input list. 
 * Additionally, a constant amount of extra space is used for variables like carry and pointers.
 */