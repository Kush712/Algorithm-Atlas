// Problem: Find the Distance Value Between Two Arrays
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for (int& num1 : arr1) {
            bool valid = true;

            for (int& num2 : arr2) {
                if (abs(num1 - num2) <= d) {
                    valid = false;
                    break;
                }
            }

            count += valid;
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    int result = solution.findTheDistanceValue(arr1, arr2, d);
    cout << "Distance Value: " << result << endl; // Output: Distance Value: 2

    return 0;
}