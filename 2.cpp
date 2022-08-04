/*

URL: https://leetcode.com/problems/add-two-numbers/ 

-----------------------------------------------------------------------------------------------------------------------

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

-----------------------------------------------------------------------------------------------------------------------

Example 1:
Image URL: https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
-----------------------------------------------------------------------------------------------------------------------

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
-----------------------------------------------------------------------------------------------------------------------

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

-----------------------------------------------------------------------------------------------------------------------

*/

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
