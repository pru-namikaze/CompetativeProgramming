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
    ListNode* addZeroIfNull(ListNode* node) {
        if(node->next == NULL){
            node->next = new ListNode();
        }
        return node->next;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carryOver = false;
        ListNode* result = l1;
        
        while(true) {
            int sum = l1->val + l2->val + (carryOver == true ? 1: 0);
            l1->val = sum  % 10;
            carryOver =  (sum / 10 > 0 ? true: false);
            
            if(l1->next == NULL && l2->next == NULL && carryOver == false) 
                break;
            else  {
                l1 = addZeroIfNull(l1);
                l2 = addZeroIfNull(l2);
            }
        }
        
        return result;
    }
};
