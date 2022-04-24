/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.
 

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and returns number of possible ways modulo 1003.

 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)

 

Constraints:
1 ≤ N ≤ 200 
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int mat[201][201][2];
    int solve(string s,int i,int j, bool isTrue){
        if(mat[i][j][isTrue] != -1)
            return mat[i][j][isTrue];
        if(i>j){
            return mat[i][j][isTrue] = 0;
        }
        if(i==j){
            if(isTrue){
                if(s[i]=='T')
                    return mat[i][j][isTrue] = 1;
                else
                    return mat[i][j][isTrue] = 0;
            }
            else{
                if(s[i]=='F')
                    return mat[i][j][isTrue] = 1;
                else
                    return mat[i][j][isTrue] = 0;
            }
        }
        int ans = 0;
        
        for(int k=i+1;k<=j-1;k+=2){
            int lt,rt,lf,rf;
        if(mat[i][k-1][true] != -1)
        {
            lt = mat[i][k-1][true];
        }
        else
        {
            lt = solve(s, i ,k-1 , true);
            mat[i][k-1][true] = lt;
        }

        if(mat[k+1][j][false] != -1)
        {
            rf = mat[k+1][j][false];
        }
        else
        {
            rf = solve(s, k+1 ,j , false);
            mat[k+1][j][false] = rf;
        }

        if(mat[i][k-1][false] != -1)
        {
            lf =  mat[i][k-1][false];
        }
        else
        {
            lf = solve(s, i ,k-1 , false);
            mat[i][k-1][false] = lf;
        }

        if(mat[k+1][j][true] != -1)
        {
            rt = mat[k+1][j][true];
        }
        else
        {
            rt = solve(s, k+1 ,j , true);
            mat[k+1][j][true] = rt;
        }
        
        
            if(s[k]=='|'){
                if(isTrue){
                    ans += lt*rt + lt*rf + lf*rt;
                }
                else{
                    ans += lf * rf;
                }
            }
            else if(s[k]=='&'){
                if(isTrue)
                    ans += lt * rt;
                else
                    ans += lf*rf + lf*rt + lt*rf;
            }
            else if(s[k]=='^'){
                if(isTrue)
                    ans += lf*rt + lt*rf;
                else
                    ans += lt*rt + lf*rf;
            }
        }
            
        return mat[i][j][isTrue] = ans%1003;
    }
public:
    int countWays(int N, string S){
        memset(mat,-1,sizeof(mat));
        return solve(S,0,S.length()-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
