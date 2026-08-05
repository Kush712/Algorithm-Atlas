// leetcode problem 3310 Remove Methods From Project
// https://leetcode.com/problems/remove-methods-from-project/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        vector<bool> sus(n,false);

        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //BFS
        queue<int> que;
        que.push(k);
        sus[k] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();

            for(int &ngbr : adj[curr]){
                inDegree[ngbr]--;
                if(!sus[ngbr]){
                    que.push(ngbr);
                    sus[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool canNotRemove = false;
        for(int i = 0;i < n; i++){
            if(sus[i] && inDegree[i] > 0){
                canNotRemove = true;
                break;
            }

            if(!sus[i]){
                result.push_back(i);
            }
        }

        if(canNotRemove){
            vector<int> vec(n);
            for(int i = 0; i < n; i++){
                vec[i] = i;
            }
            return vec;
        }

        return result;
    }
};

int main() {
    Solution solution;
    int n = 5;
    int k = 2;
    vector<vector<int>> invocations = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<int> result = solution.remainingMethods(n, k, invocations);
    
    cout << "Remaining methods: ";
    for(int method : result) {
        cout << method << " ";
    }
    cout << endl;

    int n2 = 5;
    int k2 = 0;
    vector<vector<int>> invocations2 = {{1, 2}, {0, 2},{0, 1},{3, 4}};
    vector<int> result2 = solution.remainingMethods(n2, k2, invocations2);
    cout << "Remaining methods: ";  
    for(int method : result2) {
            cout << method << " ";
        }
    cout << endl;
    return 0;
}   