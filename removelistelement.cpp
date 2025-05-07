#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove elements
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0); // Create dummy node
        dummy->next = head;
        ListNode* current = dummy;

        while (current && current->next) {
            if (current->next->val == val) {
                current->next = current->next->next; // Skip the node
            } else {
                current = current->next; // Move to next node
            }
        }

        return dummy->next;
    }
};

// Helper functions to test
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(const vector<int>& vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : vals) {
        if (!head) {
            head = new ListNode(val);
            tail = head;
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    vector<int> input = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    ListNode* head = createList(input);
    Solution sol;
    ListNode* result = sol.removeElements(head, val);
    printList(result); // Output: 1 2 3 4 5
    return 0;
}
