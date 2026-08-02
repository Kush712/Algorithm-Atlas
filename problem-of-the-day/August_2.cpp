// leetcode problem 877 Stone Game
// https://leetcode.com/problems/stone-game/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Solution {
public:
    int t[501][501];
    int solve(int i, int j, vector<int>& piles){
        if(i > j){
            return 0;
        }
        if(i == j){
            return piles[i];
        }
        if(t[i][j] != -1){
            return t[i][j];
        }

        int take_i = piles[i] + min(solve(i + 2, j, piles), solve(i + 1, j - 1, piles));    
        int take_j = piles[j] + min(solve(i + 1, j - 1, piles), solve(i, j - 2, piles));
        
        return t[i][j] = max(take_i, take_j);   
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = 0;    
        for(int i = 0; i < n; i++){
            total += piles[i];      
        }
        memset(t, -1, sizeof(t));

        int Alice = solve(0, n - 1,piles);
        int Bob = total - Alice;    

        return Alice > Bob; 
    }
};

int main(){
    Solution s;
    vector<int> piles = {5,3,4,5};
    cout << s.stoneGame(piles) << endl; // Output: 1 (true)
    return 0;
}