/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/

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
private:
    ListNode* reverse(ListNode *head){
        ListNode *prev = NULL,*next, *temp = head;
        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return;
        ListNode *slow = head, *fast = head->next->next;
        while(fast && fast->next){
            slow = slow->next;
            fast =fast->next->next;
        }
        ListNode *l1 = head;
        ListNode *ans= new ListNode();
        ListNode *l2 = reverse(slow->next);
        slow->next = NULL;
        bool flag = true;
        while(l1 && l2){
            if(flag){
                ans->next = l1;
                l1 = l1->next;
                flag = false;
            }
            else{
                ans->next = l2;
                l2 = l2->next;
                flag = true;
            }
            ans = ans->next;
        }
        if(!l1)
            ans->next = l2;
        if(!l2)
            ans->next = l1;
    }
};
