// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int multiply(int arr[], int n);


int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	    int n,sum1=0,sum2=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    
	    cout << multiply(a, n) << endl;
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

int multiply(int arr[], int n)
{
    // Complete the function
    int larr[n/2],rarr[n/2+1],sumr=0,suml=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
    if(i<n/2){
    larr[i]=arr[i];
    suml+=larr[i];
    continue;
    }
    else
    rarr[j]=arr[i];
    sumr+=rarr[j];
    j++;
    }
    return sumr*suml;
}