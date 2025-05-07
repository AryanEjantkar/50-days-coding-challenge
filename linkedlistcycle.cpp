#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true; // Empty or single-node list is a palindrome
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Find the middle of the linked list
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow;
        if (fast) { // Odd number of nodes, move the second half pointer one step forward
            secondHalf = slow->next;
        }

        // Reverse the second half
        ListNode* reversedSecondHalf = reverseList(secondHalf);

        // Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        while (reversedSecondHalf) {
            if (firstHalf->val != reversedSecondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }

        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

// Function to create a linked list for testing
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list for testing
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Example usage
    int arr1[] = {1, 2, 2, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, n1);
    std::cout << "List 1: ";
    printLinkedList(head1);
    Solution solution;
    std::cout << "Is palindrome: " << solution.isPalindrome(head1) << std::endl; // Output: 1 (true)

    int arr2[] = {1, 2, 3, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, n2);
    std::cout << "List 2: ";
    printLinkedList(head2);
    std::cout << "Is palindrome: " << solution.isPalindrome(head2) << std::endl; // Output: 1 (true)

    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    ListNode* head3 = createLinkedList(arr3, n3);
    std::cout << "List 3: ";
    printLinkedList(head3);
    std::cout << "Is palindrome: " << solution.isPalindrome(head3) << std::endl; // Output: 0 (false)
    
    int arr4[] = {1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    ListNode* head4 = createLinkedList(arr4, n4);
    std::cout << "List 4: ";
    printLinkedList(head4);
    std::cout << "Is palindrome: " << solution.isPalindrome(head4) << std::endl; // Output: 1 (true)

    return 0;
}

