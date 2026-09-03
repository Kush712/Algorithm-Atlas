// problem: 3876. Construct Uniform Parity Array II
// https://leetcode.com/problems/construct-uniform-parity-array-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEle = *min_element(begin(nums1),end(nums1));

        if(minEle % 2 == 1){ // odd. so we can convert all even to odd
            return true;
        }

        for(auto &nums : nums1){ // check for all even
            if(nums % 2 == 1){
                return false;
            }
        }
        return true;
        
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    bool result = solution.uniformArray(nums1);
    cout << "Is the array uniform? " << (result ? "Yes" : "No") << endl;

    vector<int> nums2 = {2, 4, 6, 8};
    result = solution.uniformArray(nums2);
    cout << "Is the array uniform? " << (result ? "Yes" : "No") << endl;

    vector<int> nums3 = {1, 3, 5, 7};
    result = solution.uniformArray(nums3);
    cout << "Is the array uniform? " << (result ? "Yes" : "No") << endl;

    vector<int> nums4 = {1, 2, 3, 5};
    result = solution.uniformArray(nums4);
    cout << "Is the array uniform? " << (result ? "Yes" : "No") << endl;
    return 0;
}
