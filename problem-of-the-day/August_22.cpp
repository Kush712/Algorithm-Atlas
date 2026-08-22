#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int orig = n;
        int sum = 0;
        int prod = 1;
        
        while (n > 0) {
            int dig = n % 10;
            sum += dig;
            prod *= dig;
            n = n / 10;
        }
        if ((orig % (sum + prod)) == 0) {
            return true;
        } 
        else {
            return false;
        }
    }
};

int main() {
    Solution sol;
    int n = 123; // Example input
    if (sol.checkDivisibility(n)) {
        cout << n << " is divisible by the sum and product of its digits." << endl;
    } else {
        cout << n << " is not divisible by the sum and product of its digits." << endl;
    }

    int n2 = 456; // Another example input
    if (sol.checkDivisibility(n2)) {
        cout << n2 << " is divisible by the sum and product of its digits." << endl;
    } else {
        cout << n2 << " is not divisible by the sum and product of its digits." << endl;
    }

    int n3 = 0; // Edge case input
    if (sol.checkDivisibility(n3)) {
        cout << n3 << " is divisible by the sum and product of its digits." << endl;
    } else {
        cout << n3 << " is not divisible by the sum and product of its digits." << endl;
    }
    
    return 0;
}