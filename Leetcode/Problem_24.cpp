/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto front = new ListNode();
        front->next = head;
        auto first = front;
        auto second = head;
        auto third = head->next;
        while (second && third) {
            second->next = third->next;
            third->next = second;
            first->next = third;

            first = first->next->next;
            second = first->next;
            third = second ? second->next : nullptr;
        }

        return front->next;
    }
};
