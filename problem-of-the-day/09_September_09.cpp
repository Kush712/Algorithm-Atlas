// problem : Count Commas in Range II
// https://leetcode.com/problems/count-commas-in-range-ii/

#include <iostream>
using namespace std;

class Solution {
public:
    int countCommas(long long  n){
        long long start = 1000;
        long long result = 0;

        while(start <= n){
            result += (n - start + 1);
            start *= 1000;
        }
        return result;
    }
};

int main() {
    Solution solution;
    long long n = 10000; // Example input
    long long result = solution.countCommas(n);
    cout << "Number of commas in range 1 to " << n << ": " << result << endl;

    long long n2 = 999; // Example input
    long long result2 = solution.countCommas(n2);
    cout << "Number of commas in range 1 to " << n2 << ": " << result2 << endl;

    long long n3 = 1009; // Example input
    long long result3 = solution.countCommas(n3);
    cout << "Number of commas in range 1 to " << n3 << ": " << result3 << endl;

    long long n4 = 784953973469; // Example input
    long long result4 = solution.countCommas(n4);
    cout << "Number of commas in range 1 to " << n4 << ": " << result4 << endl;
    return 0;
}