// leetcode problem 486 Predict the Winner
// https://leetcode.com/problems/predict-the-winner/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if(i > j) {
            return 0;
        }else if(i == j) {
            return nums[i];
        }

        int pick_i = nums[i] + min(solve(i+2,j,nums) , solve(i+1,j-1,nums));
        int pick_j = nums[j] + min(solve(i,j-2,nums) , solve(i+1,j-1,nums));   

        return max(pick_i, pick_j);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += nums[i];
        }
        
        int player_1 = solve(0,n-1,nums);
        int player_2 = total - player_1;

        return player_1 >= player_2;
    }   
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 2};
    bool result = solution.PredictTheWinner(nums);
    cout << (result ? "Player 1  wins." : "Player 2 wins.") << endl;

    vector<int> nums2 = {1, 5, 233, 7};
    bool result2 = solution.PredictTheWinner(nums2);
    cout << (result2 ? "Player 1 wins." : "Player 2 wins.") << endl;

    vector<int> nums3 = {1, 5, 2, 4};
    bool result3 = solution.PredictTheWinner(nums3);
    cout << (result3 ? "Player 1 wins." : "Player 2 wins.") << endl;
    return 0;
}