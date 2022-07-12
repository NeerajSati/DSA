// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// Follow-up: Can you solve the problem in O(1) extra memory space?

class Solution {
private:
    ListNode *reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev = new ListNode(-1), *newHead = prev;
        while(curr){
            ListNode *temp = curr;
            int i = 0;
            for(i=0;i<(k-1) && curr != NULL && curr->next != NULL;i++){
                curr = curr->next;
            }
            if(i != (k-1)){
                prev->next = temp;
                break;
            }
            ListNode *next;
            next = curr->next;
            curr->next = NULL;
            prev->next = reverse(temp);
            prev = temp;
            curr = next;
        }
        return newHead->next;
    }
};
