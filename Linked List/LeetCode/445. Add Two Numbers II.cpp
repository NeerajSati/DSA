/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
ListNode *reverse(ListNode *head){
    ListNode *prev = NULL,*next;
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *temp1=l1,*temp2 = l2;
            int carry = 0;
        ListNode *dummy = new ListNode(),*x = dummy;
        while((temp1 || temp2) || carry>0){
            int sum = carry;
            if(temp1){
                sum+=temp1->val;
                temp1 = temp1->next;
            }
            if(temp2){
                sum+=temp2->val;
                temp2 = temp2->next;
            }

            ListNode *some = new ListNode(sum%10);
            carry = sum/10;
            x->next = some;
            x = x->next;
        }
        dummy = reverse(dummy->next);
        return dummy;
        
    }
};
