// The whole catch is in the line 26, since we are dealing with strings here (not integers) arithmetic operations become
//hectic as ASCII code is ionvolved so we have to use -48 in order to remove the ASCII code problem




// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> stk;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]!='*'&&S[i]!='/'&&S[i]!='+'&&S[i]!='-')
            {
                stk.push(S[i]-48);
                
            }
            else{
                int temp = stk.top();
                stk.pop();
                if(S[i]=='/')
                temp = stk.top()/temp;
                else if(S[i]=='*')
                temp = stk.top()*temp;
                else if(S[i]=='+')
                temp = stk.top()+temp;
                else if(S[i]=='-')
                temp = stk.top()-temp;
                stk.pop();
                stk.push(temp);
            }
            
        }
        
        return stk.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
