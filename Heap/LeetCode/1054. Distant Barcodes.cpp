// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

// Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

// Example 1:

// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]
// Example 2:

// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]
 

// Constraints:

// 1 <= barcodes.length <= 10000
// 1 <= barcodes[i] <= 10000

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> hm;
        for(auto &it: barcodes){
            hm[it]++;
        }
        priority_queue<pair<int,int>> maxh;
        for(auto &it : hm){
            maxh.push({it.second,it.first});
        }
        vector<int> ans;
        while(!maxh.empty()){
            pair<int,int> x = maxh.top();
            maxh.pop();
            x.first--;
            ans.push_back(x.second);
            if(!maxh.empty()){
                pair<int,int> x2 = maxh.top();
                maxh.pop();
                ans.push_back(x2.second);
                x2.first--;
                if(x2.first)
                    maxh.push(x2);
            }
            if(x.first)
                maxh.push(x);
        }
        return ans;
    }
};
