#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to group odd and even indexed nodes
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create a linked list
ListNode* createList(const initializer_list<int>& vals) {
    ListNode* head = nullptr;
    ListNode** curr = &head;
    for (int val : vals) {
        *curr = new ListNode(val);
        curr = &((*curr)->next);
    }
    return head;
}

int main() {
    ListNode* head = createList({1, 2, 3, 4, 5});
    cout << "Original list: ";
    printList(head);

    head = oddEvenList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}
