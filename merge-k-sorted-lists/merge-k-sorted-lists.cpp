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
// NOTE - I know this is a bad solution. Right now I don't know enough to make this more efficient. Will come back to it later.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode();
        ListNode * sll = head;
        ListNode * chosen_node = nullptr;
        int chosen_idx;
        while(true){
            int minimum = INT_MAX;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != nullptr and lists[i] -> val < minimum) {
                    minimum = lists[i] -> val;
                    chosen_node = lists[i];
                    chosen_idx = i;
                }
            }
            if(minimum == INT_MAX) break;
            lists[chosen_idx] = lists[chosen_idx] -> next;
            sll -> next = new ListNode(minimum);
            sll = sll -> next;
        }
        return head -> next;
    }
};
