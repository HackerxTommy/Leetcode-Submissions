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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while( fast   && fast -> next){
            slow = slow -> next;
            fast = fast -> next ->next;
             
             if (  fast == slow) break; //cycle formed
        }
        if ( ! (fast && fast-> next) ) return NULL;
        while( head != slow){ // after sometime head will also reach start of cycle and so slow too
            head = head ->next;
            slow = slow -> next;
        }
        return head;
        
    }
};