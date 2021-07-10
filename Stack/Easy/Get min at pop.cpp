// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends
//User function Template for C++

int minEle;
//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
    stack<int> s;
    minEle = arr[0];
    s.push(arr[0]);
    
   for(int i=1;i<n;i++)
   {
       if(arr[i]<minEle)
       {
           s.push(2*arr[i] - minEle);
           minEle = arr[i];
       }
       else
       s.push(arr[i]);
   }
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    while(s.empty() == false)
    {
        if (s.top() < minEle)
        {
            cout << minEle << " ";
            minEle = 2*minEle - s.top();
        }
        else
            cout << s.top() << " ";
        s.pop();
    }
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    
	    
	}
	return 0;
}

  // } Driver Code Ends
