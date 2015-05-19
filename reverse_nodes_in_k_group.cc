/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool checkSize(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        while (curr != nullptr && len < k) {
            curr = curr->next;
            ++len;
        }
        return len >= k;
    }
    ListNode* reverseListN(ListNode* head, int n) {
        if (head == nullptr || n == 0) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < n && curr != nullptr; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr;  // point to the rest of the list
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* curr = head;
        ListNode* prev = &dummy;
        while (curr != nullptr && checkSize(curr, k)) {
            ListNode* new_head = reverseListN(curr, k);
            prev->next = new_head;
            prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = head;
        ListNode *cur = head;
        ListNode *newHead = nullptr;
        while(cur != nullptr) {
            cur = cur->next;
            prev->next = newHead;
            newHead = prev;
            prev = cur;
        }
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *left = &dummy;
        ListNode *right = &dummy;
        int count = 0;
        while(right != nullptr) {
            if(count < k) {
                right = right->next;
                ++count;
            }else {
                ListNode *reverseHead = left->next;
                ListNode *next = right->next;
                right->next = nullptr;
                ListNode *newHead = reverseList(reverseHead);
                left->next = newHead;
                reverseHead->next = next;
                count = 0;
                left = reverseHead;
                right = reverseHead;
            }
        }
        return dummy.next;
    }
};
