/*
Given two string, represented as linked lists (every character is a node->data in the linked list). Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are same, 1 if first linked list is lexicographically greater, and -1 if second is lexicographically greater.

Input:
First line of input contains number of testcases T. For each testcase, there will be 4 lines of input. First line of which contains length of first linked list and next line contains the linked list, similarly next two lines contains length and linked list respectively.

Output:
Comapare two strings represented as linked list.

User Task:
The task is to complete the function compare() which compares the strings through linked list and returns 0, 1 or -1 accordingly.

Constraints:
1 <= T <= 100
1 <= N, M <= 100

Example:
Input:
2
5
a b a b a
4
a b a a
3
a a b
3
a a b

Output:
1
0

Explanation:
Testcase 1: String consisting of nodes of first linked list is lexicographically greater than the second one. So, the result is 1.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;  
// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};  


int compare(Node *list1, Node *list2); 


int main()
{
 int t,n;
 cin>>t;
 char x;
 while(t--)
 {
 cin>>n;
 cin>>x;
  Node *list1 = new Node(x);
    Node *temp=list1;
    for(int i=0;i<n-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
		int m;
		cin>>m;
    cin>>x;
    Node *list2 = new Node(x);
    temp=list2;
    for(int i=0;i<m-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
 
    cout << compare(list1, list2)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};
*/

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 
{
     string s1,s2;
     while(list1 && list2 && list1->c == list2->c)
     {
         list1 = list1->next;
         list2 = list2->next;
     }
    if (list1 && list2)
    return (list1->c > list2->c)? 1: -1;
    else if (list1 && !list2) 
    return 1;
    else if (list2 && !list1) 
    return -1;
    
    return 0;
}
