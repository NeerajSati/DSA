// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    private:
    bool matching(char a, char b)
    {
        return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
    }
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<int> s;
        for(int i=0;i<x.length();i++)
        {
            if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            {
            s.push(x[i]);
            }
            else
            {
            if(s.empty())
            return false;
            else if(matching(s.top(),x[i])==false)
            return false;
            else
            s.pop();
            }
            
        }
        return (s.empty() == true);
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
