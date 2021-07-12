/*
Tom is a string freak. He has got sequences of  n words to manipulate. If in a sequence, two same words come together then he’ll destroy each other. He wants to know the number of words left in the sequence after this pairwise destruction.
 

Example 1:

Input:
5
v[] = {"ab", "aa", "aa", "bcd", "ab"}
Output:
3
Explanation:
ab aa aa bcd ab
After the first iteration, we'll have: ab bcd ab
We can't further destroy more strings and
hence we stop and the result is 3. 
 

Example 2:

Input:
4
v[] = {"tom", "jerry", "jerry", "tom"}
Output:
0
Explanation:
tom jerry jerry tom
After the first iteration, we'll have: tom tom
After the second iteration: 'empty-array' 
Hence, the result is 0. 

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function removeConsecutiveSame() which takes the array A[] and its size N as inputs and returns the number of words left per sequence.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removeConsecutiveSame(vector <string > v) 
    {
        stack<string> s;
        int count=0;
        for(int i=0;i<v.size();i++)
        {
            if(s.empty() == false && s.top()==v[i])
            {
                s.pop();
                count--;
            }
            else{
        s.push(v[i]);
        count++;
            }
        }
        return count;
    } 
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n;
         cin>>n;
         string s;
         vector<string> v;
         for(int i=0;i<n;i++)
         {
             cin>>s;
             v.push_back(s);
         }
         Solution ob;
         cout<< ob.removeConsecutiveSame(v) <<endl;
     }
	
	
	
	
	return 0;
}  // } Driver Code Ends
