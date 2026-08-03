#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> t;
    int solve(vector<int>& stone,int i){
        int n = stone.size();
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int result = stone[i] - solve(stone, i + 1);    
        if(i + 1 < n){
            result = max(result, stone[i] + stone[i + 1] - solve(stone, i + 2));
        }
        if(i + 2 < n){
            result = max(result, stone[i] + stone[i + 1] + stone[i + 2] - solve(stone, i + 3));
        }

        return t[i] = result;
    }

    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        t.resize(n + 1, -1);
        int result = solve(stone, 0);

        if(result < 0){
            return "Bob";
        } else if(result > 0){
            return "Alice";
        } else {
            return "Tie";
        }
    }
};

int main() {
    Solution solution;
    vector<int> stone = {1, 2, 3, 7};
    cout << solution.stoneGameIII(stone) << endl;

    vector<int> stone3 = {1, 2, 3};
    cout << solution.stoneGameIII(stone3) << endl;  

    vector<int> stone2 = {1, 2, 3, -9};
    cout << solution.stoneGameIII(stone2) << endl;
    
    return 0;
}