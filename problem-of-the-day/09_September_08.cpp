// problem: Count Commas in Range
// https://leetcode.com/problems/count-commas-in-range/

#include<iostream>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (i >= 1000) {
                count++;
            }
        }
        return count;
    }
};
/*
    int countCommas(int n) {
        if (n < 1000)
            return 0;
        return (n - 1000) + 1;
    }
*/

int main() {
    Solution solution;
    int n = 10000; // Example input
    int result = solution.countCommas(n);
    cout << "Number of commas in range 1 to " << n << ": " << result << endl;

    int n2 = 999; // Example input
    int result2 = solution.countCommas(n2);
    cout << "Number of commas in range 1 to " << n2 << ": " << result2 << endl;

    int n3 = 1009; // Example input
    int result3 = solution.countCommas(n3);
    cout << "Number of commas in range 1 to " << n3 << ": " << result3 << endl;

    int n4 = 78495; // Example input
    int result4 = solution.countCommas(n4);
    cout << "Number of commas in range 1 to " << n4 << ": " << result4 << endl;
    return 0;
}