// Given a Binary Tree find the length of the longest path which comprises of connected nodes with consecutive values in increasing order. 

 

// Example 1:

// Input :      
//            1                               
//          /   \                          
//         2     3                      

// Output: 2

// Explanation : Longest sequence is 1, 2.

 

// Example 2:

// Input :    
//             10                               
//          /     \                          
//        20       30                      
//       /  \      /
//      40      60   90    

// Output :  -1

// Explanation: For the above test case no 
// sequence is possible. So output is -1.
 

// Your Task:  
// You dont need to read input or print anything. Complete the function longestConsecutive() which takes root node as input parameter and returns the length of the longest consecutive increasing sequence (of at least length 2) in the given Binary Tree. If such a sequence does not exist, return -1.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of Tree)


// Constraints:
// 1 ≤ N ≤ 10^3


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
struct Node
{
	int data;
	Node *left, *right;
};
*/
class Solution{
  private:
    int res = -1;
    void helper(Node* root, int size)
    {
         if(root==NULL)
            return;
        if(size>1)
            res = max(size,res);
        
        if(root->left)
            {
                if(root->left->data == (1 + root->data))
                    helper(root->left,size+1);
                else
                    helper(root->left,1);
            }
        if(root->right)
            {
                if(root->right->data == (1 + root->data))
                    helper(root->right,size+1);
                else
                    helper(root->right,1);
            }
    }
  public:
    int longestConsecutive(Node* root)
    {
        helper(root, 1);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        cout<<obj.longestConsecutive(root)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
