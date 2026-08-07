// leetcode problem 33348 smallest divisible digit product 2
// https://leetcode.com/problems/smallest-divisible-digit-product-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    typedef long long ll;

    ll gcd(ll a, ll b)
    {
        while (b != 0)
        {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string freeSlotsFiller(ll required, int length)
    {
        string str;

        for (int digit = 9; digit >= 2; digit--)
        {
            while (required % digit == 0)
            {
                str.push_back(digit + '0');
                required /= digit;
            }
        }

        // If some factor is still left, it's impossible
        if (required != 1)
            return "";

        while ((int)str.length() < length)
        {
            str.push_back('1');
        }

        if ((int)str.length() > length)
            return "";

        reverse(str.begin(), str.end());

        return str;
    }

    string smallestNumber(string num, long long t)
    {
        int n = num.length();

        ll temp = t;
        for (int primeFact : {2, 3, 5, 7})
        {
            while (temp % primeFact == 0)
            {
                temp /= primeFact;
            }
        }

        if (temp != 1)
        {
            return "-1";
        }

        vector<ll> remainingFactor(n + 1, t);

        for (int i = 0; i < n; i++)
        {
            int digit = num[i] - '0';

            if (digit == 0)
            {
                break;
            }

            remainingFactor[i + 1] =
                remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }

        if (remainingFactor[n] == 1)
        {
            return num;
        }

        size_t zeroPos = num.find('0');
        int zeroIdx = (zeroPos == string::npos) ? n - 1 : (int)zeroPos;

        for (int i = zeroIdx; i >= 0; i--)
        {
            ll required = remainingFactor[i];
            int freeSlots = n - 1 - i;

            int startDigit = max((num[i] - '0') + 1, 1);

            for (int digit = startDigit; digit <= 9; digit++)
            {
                ll furtherRequired = required / gcd(required, (ll)digit);

                string requiredNumber =
                    freeSlotsFiller(furtherRequired, freeSlots);

                if (!requiredNumber.empty() ||
                    (freeSlots == 0 && furtherRequired == 1))
                {

                    return num.substr(0, i) +
                           char(digit + '0') +
                           requiredNumber;
                }
            }
        }

        return freeSlotsFiller(t, n + 1);
    }
};

int main()
{
    Solution solution;

    string num = "1234";
    long long t = 256;

    string result = solution.smallestNumber(num, t);
    cout << "Smallest number: " << result << endl;

    string num2 = "12355";
    long long t2 = 50;
    string result2 = solution.smallestNumber(num2, t2); 
    cout << "Smallest number: " << result2 << endl;

    string num3 = "11111";
    long long t3 = 26;    
    string result3 = solution.smallestNumber(num3, t3);
    cout << "Smallest number: " << result3 << endl;

    return 0;
}