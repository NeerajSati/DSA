#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,n,x,low,high,mid,ans;
	cin>>t;
	while(t--)
	{
	    cin>>n>>x;
	    int arr[n];
	    for (int i=0;i<n;i++)
	    cin>>arr[i];
	    sort(arr,arr+n);
	    high=n-1;
	    low=0;
	    ans=n;
	    
	    while(low<=high)
	    {
	        mid=(low+high)/2;
	        if(arr[mid]<=x)
	            low=mid+1;
	            
	        else
	        {
	            high=mid-1;
	            ans=mid;
	        }
	    }
	    cout<<n-ans<<endl;
	}
	return 0;
}
