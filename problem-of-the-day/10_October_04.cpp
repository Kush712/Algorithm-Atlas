// problem: 2390. Removing Stars From a String
// https://leetcode.com/problems/removing-stars-from-a-string/ 

#include <iostream>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string result;

        for(auto c : s){
            if(c == '*'){
                result.pop_back();
            }
            else{
                result += c;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string input = "leet**cod*e"; // Example input
    string output = solution.removeStars(input);

    cout << "Output after removing stars: " << output << std::endl;

    string input2 = "erase*****"; // Another example input
    string output2 = solution.removeStars(input2);
    cout << "Output after removing stars: " << output2 << std::endl;

    string input3 = "abc*de*f*"; // Another example input
    string output3 = solution.removeStars(input3);
    cout << "Output after removing stars: " << output3 << std::endl;

    return 0;
}