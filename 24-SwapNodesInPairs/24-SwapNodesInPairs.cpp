// Last updated: 8/31/2025, 10:50:33 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        head = node2;
        while (node1 != nullptr && node2 != nullptr) {
            ListNode* nex = node2->next;
            node2->next = node1;
            node1->next = nex;
            if (pre != nullptr) pre->next = node2;
            pre = node1;
            node1 = nex;
            if (nex != nullptr) node2 = nex->next;
            else node2 = nullptr;
        }
        return head;
    }
};