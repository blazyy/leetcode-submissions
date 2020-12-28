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

// Time Complexity - O(n log k) where k is the number of linked lists
// Space Complexity- O(n) but can be reduced to O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int, vector<int>, greater<int>> min_heap;
        for(auto list : lists){
            ListNode * current = list;
            while(current){
                min_heap.push(current -> val);
                current = current -> next;
            }
        }
        ListNode * head = new ListNode();
        ListNode * sll = head;
        while(!min_heap.empty()){
            sll -> next = new ListNode(min_heap.top());
            min_heap.pop();
            sll = sll -> next;
        }
        return head -> next;
    }
};

// Old Solution
// Time Complexity  - O(kN) where k is the number of linked lists
// Space Complexity - O(N) - but can be reduced to O(1)
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode * head = new ListNode();
//         ListNode * sll = head;
//         ListNode * chosen_node = nullptr;
//         int chosen_idx;
//         while(true){
//             int minimum = INT_MAX;
//             for(int i = 0; i < lists.size(); i++) {
//                 if(lists[i] != nullptr and lists[i] -> val < minimum) {
//                     minimum = lists[i] -> val;
//                     chosen_node = lists[i];
//                     chosen_idx = i;
//                 }
//             }
//             if(minimum == INT_MAX) break;
//             lists[chosen_idx] = lists[chosen_idx] -> next;
//             sll -> next = new ListNode(minimum);
//             sll = sll -> next;
//         }
//         return head -> next;
//     }
// };
