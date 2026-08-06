#include<iostream>
using namespace std;    

class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int num = n;
            int product = 1;

            while(num > 0){
                int dig = num % 10;
                product *= dig; 
                num /= 10;  
            }

            if(product % t == 0){
                return n;
            }
            n++;
        }
    }
};

int main(){
    Solution sol;
    int n = 10;
    int t = 2;
    int result = sol.smallestNumber(n, t);
    cout << "The smallest number with " << n << " digits and product " << t << " is: " << result << endl;

    int n2 = 15; 
    int t2 = 3;
    int result2 = sol.smallestNumber(n2, t2);
    cout << "The smallest number with " << n2 << " digits and product " << t2 << " is: " << result2 << endl;

    int n3 = 20;
    int t3 = 5;
    int result3 = sol.smallestNumber(n3, t3);
    cout << "The smallest number with " << n3 << " digits and product " << t3 << " is: " << result3 << endl;    

    int n4 = 25;
    int t4 = 7;
    int result4 = sol.smallestNumber(n4, t4);
    cout << "The smallest number with " << n4 << " digits and product " << t4 << " is: " << result4 << endl;
    
    return 0;
}