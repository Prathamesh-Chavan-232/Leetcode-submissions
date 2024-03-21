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
    ListNode* detectCycle(ListNode* head) {
        // Store result
        ListNode* res = NULL;
        // If the Linked list is empty or only has 1 element
        if(head == NULL || head->next == NULL) 
            return NULL;

        // making two pointers fast and slow and assignning them to head
        ListNode* fast = head;
        ListNode* slow = head;
        // till fast and fast-> next not reaches NULL
        // we will increment fast by 2 step and slow by 1 step
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            // At the point if fast and slow are at same address
            // this means linked list has a cycle in it.
            if (fast == slow) {
                slow = head;
                break;
            }
        } 
        // Now we find the node where the cycle starts
        if (slow == head) {
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            res = slow;
        }
        // if traversal reaches to NULL this means no cycle.
        return res;
    }
};