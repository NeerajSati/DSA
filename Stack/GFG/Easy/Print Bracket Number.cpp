// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> barcketNumbers(string S)
	{
	    int count=1;
	    vector<int> v;
	    stack<int> stk;
	    for(int i=0;i<S.length();i++)
	    {
	        if (S[i] == '(')
            {
            stk.push(count);
            v.push_back(count);
            count++;
            }
            else if(S[i]==')')
            {
            v.push_back(stk.top());
            stk.pop();
            }
	    }
	    return v;
	}
};

// { Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.barcketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends
