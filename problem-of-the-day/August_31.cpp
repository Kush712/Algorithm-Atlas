#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int currPosition = 1;
        int previousCriticalIndex = 0;
        int firstCriticalIndex = 0;

        while (curr->next != NULL) {
            
            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) 
            {
                if (previousCriticalIndex == 0) {
                    previousCriticalIndex = currPosition;
                    firstCriticalIndex = currPosition;
                } else {
                    minDistance = min(minDistance, currPosition - previousCriticalIndex);
                    previousCriticalIndex = currPosition;
                }
            }

            currPosition++;
            prev = curr;
            curr = curr->next;
        }

        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = previousCriticalIndex - firstCriticalIndex;
        return {minDistance, maxDistance};
    }
};

int main() {
    Solution solution;

    // Test case 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(3);
    head1->next->next->next->next->next = new ListNode(2);

    vector<int> result1 = solution.nodesBetweenCriticalPoints(head1);
    cout << "Test case 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    // Test case 2
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(1);

    vector<int> result2 = solution.nodesBetweenCriticalPoints(head2);
    cout << "Test case 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    // Test case 3
    ListNode* head3 = new ListNode(1);

    vector<int> result3 = solution.nodesBetweenCriticalPoints(head3);
    cout << "Test case 3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}