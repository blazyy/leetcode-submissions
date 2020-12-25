/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *current = head;
        while(current){
            current = current -> next;
            size++;
        }
        n = size - n;
        current = head;
        ListNode *prev = nullptr;
        
        if(n == 0)
            head = head -> next;
        else{
            while(current){
                if(n == 0){
                    prev -> next = current -> next;
                    break;
                }
                n--;
                prev = current;
                current = current -> next;
            }
        }
        return head;
    }
};
