// leetcode problem 1140 stone game ii
// https://leetcode.com/problems/stone-game-ii/

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>   
using namespace std;

class Solution {
public:
    int t[2][101][101]; 
    int solveForAlice(vector<int>& piles, int person,int i,int m){
        int n = piles.size();   
        if(i>=n) return 0;

        int stone = 0;
        int result = (person == 1)? -1 : INT_MAX;   

        if(t[person][i][m] != -1) return t[person][i][m];

        for(int x = 1; x <= min(2*m,n-i); x++){
            stone += piles[i+x-1];

            if(person == 1){
                result = max(result,stone + solveForAlice(piles,0,i+x,max(m,x)));
            }
            else{
                result = min(result,solveForAlice(piles,1,i+x,max(m,x)));
            }
        }

        return t[person][i][m] = result;
    }

    int stoneGameII(vector<int>& piles){
        memset(t,-1,sizeof(t)); 

        return solveForAlice(piles,1,0,1);
    }
};

int main() {
    Solution s;
    vector<int> piles = {2, 7, 9, 4, 4};
    int result = s.stoneGameII(piles);
    cout << "Maximum stones Alice can get: " << result << endl;

    vector<int> piles2 = {1, 2, 3, 4, 5, 100};
    result = s.stoneGameII(piles2);
    cout << "Maximum stones Alice can get: " << result << endl;
    return 0;
}