/*
Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i] is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.

Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.

Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. It is guaranteed that at least one answer exists.

 

Example 1:

Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]
Example 2:

Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]
Example 3:

Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]
 

Constraints:

1 <= aliceSizes.length, bobSizes.length <= 104
1 <= aliceSizes[i], bobSizes[j] <= 105
Alice and Bob have a different total number of candies.
There will be at least one valid answer for the given input.
*/



//Using set
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sumA=0;
        int sumB=0;
        unordered_set<int> s;
        for(auto it:a)
            sumA+=it;
        for(auto it:b){
            sumB+= it;
            s.insert(it);
        }
        int diff = sumB - sumA;
        diff /= 2;
        vector<int> ans;
        for(auto it:a)
            if(s.find(it + diff)!= s.end()){
                ans.push_back(it);
                ans.push_back(it + diff);
                break;
            }
        return ans;
  
        
    }
};




//Using Binary Search 
class Solution {
    
   private:
    bool binarySearch(vector<int> &a,int el){
        int low =0;
        int upper = a.size()-1;
        while(low<=upper){
            int mid = (upper + low)/2;
            if(a[mid] == el){
                return true;
               }
            else if(a[mid] < el)
                low = mid + 1;
            else
                upper = mid - 1;
            }
        return false;
       }
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int sumA=0;
        int sumB=0;
 
        for(auto it:a)
            sumA+=it;
        for(auto it:b){
            sumB+= it;

        }
sort(b.begin(),b.end());
        int diff = sumB - sumA;
        diff /= 2;
        vector<int> ans;
        for(auto it:a)
            if(binarySearch(b, it + diff)){
                ans.push_back(it);
                ans.push_back(it + diff);
                break;
            }
        
        return ans;
  
        
    }
};
