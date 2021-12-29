/*
Given a linked list L of N nodes, sorted in ascending order based on the absolute values of its data. Sort the linked list according to the actual values.


Example:

Input: 1 -> -2 -> -3 -> 4 -> -5
Output: -5 -> -3 -> -2 -> 1 -> 4

Constraints
1 ≤  N  ≤ 30
-100 ≤ L[i] ≤ 100
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
    Node* next;
    int data;
};
void sortList(Node** head);
// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
    Node* newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout<<endl;
}


// Driver code
int main()
{

int t=0;
int n = 0;
cin>>t;
while(t--)
{
 Node* head = NULL;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
       // push(&head, a);
    }
    for(int i=n-1;i>=0;i--)
    {
        push(&head, arr[i]);
    }
   // printList(head);

    sortList(&head);

    printList(head);

}
    return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
void sortList(Node** head)
{
    if((*head)==NULL || (*head)->next == NULL)
    return;
    Node *temp = (*head)->next;
    Node *prev = (*head);
    while(temp != NULL)
    {
        if(temp->data < 0)
        {
            prev->next = temp->next;
            temp->next = (*head);
            *head = temp;
            temp = prev->next;
            continue;
        }
        prev = temp;
        temp=temp->next;
        
        
    }
}
