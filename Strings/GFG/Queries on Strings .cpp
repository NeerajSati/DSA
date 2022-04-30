/*
Given a string str you have to answer several queries on that string. In each query you will be provided two values L and R and you have to find the number of distinct characters in the sub string from index L to index R (inclusive) of the original string.
 

Example 1:

Input: str = "abcbaed",
Query = {{1,4},{2,4},{1,7}}
Output: {3,2,5}
Explanation: For the first query distinct 
characters from [1, 4] are a, b and c.
For the second query distinct characters from
[2, 4] are b and c.
For the third query distinct characters from
[1, 7] are a, b, c, d and e.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function SolveQueries() which takes str and Query as input parameter and returns a list containing answer for each query.
 

Expected Time Complexity: O(max(26*length of str, 26 * No of queries))
Expected Space Complexity: O(26 * length of str)
 

Constraints:
1 <= |str| <= 105
1 <= No of Queries <= 104
1 <= Li <= Ri <= |str|
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    vector<int>ans;
	    
	    for(int i=0;i<Query.size();i++){
	        
	        int l=Query[i][0];
	        int r=Query[i][1];
	        
	        set<int>s;
	        
	        for(int j=l-1;j<r;j++){
	            
	            s.insert(str[j]);
	        }
	        ans.push_back(s.size());
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
