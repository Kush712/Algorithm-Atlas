// problem: 3875. Construct Uniform Parity Array I
// https://leetcode.com/problems/construct-uniform-parity-array-i/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool odd = true, even = true;

        for(int i=0; i<n; i++){
            if(nums1[i]%2==0){
                // check for odd
                bool valid = false;
                for(int j=0; j<n; j++){
                    if(i!=j && abs(nums1[i]-nums1[j])%2==1){
                        valid = true;
                    }
                }
                if(!valid) odd = false;
            }
            else {
                // check for even
                bool valid = false;
                for(int j=0; j<n; j++){
                    if(i!=j && abs(nums1[i]-nums1[j])%2==0){
                        valid = true;
                    }
                }
                if(!valid) even = false;
            }
        }

        return odd | even;
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

    return 0;
}