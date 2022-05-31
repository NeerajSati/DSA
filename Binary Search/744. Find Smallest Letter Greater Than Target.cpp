// Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

// Note that the letters wrap around.

// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 

// Example 1:

// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
// Example 2:

// Input: letters = ["c","f","j"], target = "c"
// Output: "f"
// Example 3:

// Input: letters = ["c","f","j"], target = "d"
// Output: "f"
 

// Constraints:

// 2 <= letters.length <= 104
// letters[i] is a lowercase English letter.
// letters is sorted in non-decreasing order.
// letters contains at least two different characters.
// target is a lowercase English letter.

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0,end = letters.size() - 1;
        char ans = '#';
        while(start<=end){
            int mid = start + (end - start)/2;
            if(letters[mid] == target){
                start  = mid + 1;
            }
            else if(target < letters[mid]){
                ans = letters[mid];
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        if(ans == '#')
            return letters[0];
        
        return ans;
    }
};
