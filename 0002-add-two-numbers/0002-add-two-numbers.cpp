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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ans(0);
        ListNode* temp = &ans;
        int carry = 0;
        while(l1 || l2 || carry){
            int x = l1 ? l1 -> val : 0;
            int y = l2 ? l2 -> val : 0;
            int sum = x + y + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            temp -> next = newNode;
            temp = temp -> next;
            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }
        return ans.next;
    }
};
