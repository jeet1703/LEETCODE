#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class as provided
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode(0);
        ListNode *curr = temp;
        int carry = 0;
        while(l1!= NULL || l2 != NULL || carry>0){
            if(l1!=NULL){
                carry+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                carry+=l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(carry%10);
            carry = carry/10;
            curr = curr->next;
        }
        return temp->next;
    }
};

// Utility function to create a linked list from a vector of integers
ListNode* createList(const std::vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Test Case 1
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    ListNode* result = solution.addTwoNumbers(l1, l2);
    std::cout << "Test Case 1: ";
    printList(result);  // Expected Output: 7 -> 0 -> 8

    // Test Case 2
    l1 = createList({0});
    l2 = createList({0});
    result = solution.addTwoNumbers(l1, l2);
    std::cout << "Test Case 2: ";
    printList(result);  // Expected Output: 0

    // Test Case 3
    l1 = createList({9, 9, 9, 9, 9, 9, 9});
    l2 = createList({9, 9, 9, 9});
    result = solution.addTwoNumbers(l1, l2);
    std::cout << "Test Case 3: ";
    printList(result);  // Expected Output: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1

    // Test Case 4
    l1 = createList({2, 4, 3});
    l2 = createList({5, 6});
    result = solution.addTwoNumbers(l1, l2);
    std::cout << "Test Case 4: ";
    printList(result);  // Expected Output: 7 -> 0 -> 4

    // Free allocated memory (optional but recommended)
    // Note: In practice, you'd also want to delete the linked lists created in the test cases.
    
    return 0;
}
