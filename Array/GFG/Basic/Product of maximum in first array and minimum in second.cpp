/*
Given two arrays of A and B respectively of sizes N1 and N2, the task is to calculate the product of the maximum element of the first array and minimum element of the second array.

Example 1:

Input : A[] = {5, 7, 9, 3, 6, 2}, 
        B[] = {1, 2, 6, -1, 0, 9}
Output : -9
Explanation:
The first array is 5 7 9 3 6 2. 
The max element among these elements is 9.
The second array is 1 2 6 -1 0 9.
The min element among these elements is -1.
The product of 9 and -1 is 9*-1=-9.
*/

#include <bits/stdc++.h>

using namespace std;


long long find_multiplication(int a[], int b[], int n, int m);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)    cin>>a[i];
        
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++)    cin>>b[i];
        
        
        
        cout<<find_multiplication(a, b, n, m)<<endl;

    }
    return 0;
}// } Driver Code Ends


long long find_multiplication(int a[], int b[], int n, int m)
{
    int max=a[0],min=b[0];
    for(int i=0;i<n;i++)
    if(a[i]>max)
    max=a[i];
    
    for(int i=0;i<m;i++)
    if(b[i]<min)
    min=b[i];
    
    return max*min;
    
}

