// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int count=0;
        stack<int> stk;
        stk.push(-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            stk.push(i);
            else
            {
                if(stk.empty() == false)
                stk.pop();
                if(stk.empty() == false)
                count = max(count , i-stk.top());
                else
                stk.push(i);
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
