// problem: 1807. Evaluate the Bracket Pairs of a String
// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        vector<int> temp;

        while(n > 0){
            unsigned int dig = n % 10;
            temp.push_back(dig);
            n = n/10;
        }

        sort(temp.begin(),temp.end());

        unsigned int n1 = temp.size();
        return temp[n1-1] * temp[n1-2];;
    }
};

int main() {
    Solution solution;
    int n = 29; // Example input
    int result = solution.maxProduct(n);
    cout << "The maximum product of two digits in " << n << " is: " << result << endl;

    int n2 = 836;
    int result1 = solution.maxProduct(n2);
    cout << "The maximum product of two digits in " << n2 << " is: " << result1 << endl;

    int n3 = 12345;
    int result2 = solution.maxProduct(n3);
    cout << "The maximum product of two digits in " << n3 << " is: " << result2 << endl;
    return 0;
}