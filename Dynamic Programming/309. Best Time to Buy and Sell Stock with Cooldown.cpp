// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
// Example 2:

// Input: prices = [1]
// Output: 0
 

// Constraints:

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000


class Solution {
private:
    int helper(vector<int>& prices, int curr, int i, int n,map<pair<int,int>,int> &hm){
        if(i>=n)
            return 0;
        if(hm.find({i,curr}) !=hm.end())
            return hm[{i,curr}];
            
        int profit;
        if(prices[i] <= curr){
            //We buy the stock if this stock is less costly than what we are holding
            profit = helper(prices,prices[i],i+1,n,hm);
        }
        else{
            //We either sell the stock and go to cool down, or we wait further
            profit = max(helper(prices,curr,i+1,n,hm), prices[i] - curr + helper(prices,INT_MAX,i+2,n,hm));
        }
        return hm[{i,curr}] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        map<pair<int,int>,int> hm;
        return helper(prices,INT_MAX,0,n,hm);
    }
};
