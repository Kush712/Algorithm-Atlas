// leetcode problem 3986 Number of Elapsed Seconds Between Two Times
// https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int toSeconds(string time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));
        return h * 3600 + m * 60 + s;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        return toSeconds(endTime) - toSeconds(startTime);
    }
};

int main() {
    Solution sol;
    string start1 = "12:30:00";
    string end1 = "13:45:30";
    cout << "Elapsed seconds: " << sol.secondsBetweenTimes(start1, end1) << endl;

    string start2 = "00:00:00";
    string end2 = "23:59:59";
    cout << "Elapsed seconds: " << sol.secondsBetweenTimes(start2, end2) << endl;

    string start3 = "10:00:00";
    string end3 = "10:00:00";
    cout << "Elapsed seconds: " << sol.secondsBetweenTimes(start3, end3) << endl;

    string start4 = "01:15:30";
    string end4 = "02:30:45";
    cout << "Elapsed seconds: " << sol.secondsBetweenTimes(start4, end4) << endl;

    return 0;
}
