#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* findMiddleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Helper function to create a linked list from a vector of integers
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to convert a linked list to a vector of integers for output
std::vector<int> linkedListToVector(ListNode* head) {
    std::vector<int> output;
    ListNode* current = head;
    while (current != nullptr) {
        output.push_back(current->val);
        current = current->next;
    }
    return output;
}

// Helper function to free the memory allocated for the linked list
void freeLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    // Example 1
    std::vector<int> head1_values = {1, 2, 3, 4, 5};
    ListNode* head1 = createLinkedList(head1_values);
    ListNode* middle1 = findMiddleNode(head1);
    std::vector<int> output1 = linkedListToVector(middle1);
    std::cout << "Input: head = [";
    for (size_t i = 0; i < head1_values.size(); ++i) {
        std::cout << head1_values[i] << (i == head1_values.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;
    std::cout << "Output: [";
    for (size_t i = 0; i < output1.size(); ++i) {
        std::cout << output1[i] << (i == output1.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;
    std::cout << "Explanation: The middle node of the list is node " << middle1->val << "." << std::endl;
    std::cout << "--------------------" << std::endl;
    freeLinkedList(head1);

    // Example 2
    std::vector<int> head2_values = {1, 2, 3, 4, 5, 6};
    ListNode* head2 = createLinkedList(head2_values);
    ListNode* middle2 = findMiddleNode(head2);
    std::vector<int> output2 = linkedListToVector(middle2);
    std::cout << "Input: head = [";
    for (size_t i = 0; i < head2_values.size(); ++i) {
        std::cout << head2_values[i] << (i == head2_values.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;
    std::cout << "Output: [";
    for (size_t i = 0; i < output2.size(); ++i) {
        std::cout << output2[i] << (i == output2.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;
    std::cout << "Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one (" << middle2->val << ")." << std::endl;
    freeLinkedList(head2);

    return 0;
}