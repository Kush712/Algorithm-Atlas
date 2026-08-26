// leetcode problem 3973 Distinct Gate Paths to LCA
// https://leetcode.com/problems/distinct-gate-paths-to-lca/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> depth;

    void dfs(int node, int par, int d) {
        parent[node] = par;
        depth[node] = d;
        for (int &child : adj[node]) {
            if (child != par) {
                dfs(child, node, d + 1);
            }
        }
    }

    int lca(int u, int v) {
        while (depth[u] > depth[v]) u = parent[u];
        while (depth[v] > depth[u]) v = parent[v];
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }
        return u;
    }

    int countPaths(int node, int target) {
        int count = 0;
        while (node != target) {
            node = parent[node];
            count++;
        }
        return count;
    }

    vector<int> distinctGatePaths(int n, vector<vector<int>>& edges, vector<int>& gates, int u, int v) {
        adj.resize(n);
        parent.resize(n);
        depth.resize(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, 0);
        int ancestor = lca(u, v);

        vector<int> result;
        for (int gate : gates) {
            int g_lca = lca(gate, ancestor);
            if (g_lca == ancestor) {
                result.push_back(countPaths(gate, ancestor));
            }
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5}};
    vector<int> gates = {3, 4, 5};
    int u = 3, v = 5;
    vector<int> result = sol.distinctGatePaths(n, edges, gates, u, v);

    cout << "Distinct gate paths to LCA: ";
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
