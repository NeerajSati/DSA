/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

class Solution {
private:
    int countSubSum(vector<int>& nums, int sum){
        int mat[nums.size()+1][sum+1];
        for(int i=0;i<=nums.size();i++){
            mat[i][0] = 1;
        }
        for(int j=1;j<=sum;j++){
            mat[0][j] = 0;
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1] <= j){
                    mat[i][j] = mat[i-1][j] + mat[i-1][j-nums[i-1]];
                }
                else{
                    mat[i][j] = mat[i-1][j];
                }
            }
        }
        return mat[nums.size()][sum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        if(sum < abs(target) || (target+sum) % 2 != 0)
            return 0;
        
        return countSubSum(nums,(target+sum)/2);
        
    }
};
