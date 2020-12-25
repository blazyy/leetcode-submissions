# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
​
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if headA is None or headB is None:
            return None
        currA = headA
        currB = headB
        tailA = None
        tailB = None
        
        while True:
            if currA == currB:
                return currA
            
            if currA.next:
                currA = currA.next
            else:
                tailA = currA
                currA = headB
​
            if currB.next:
                currB = currB.next
            else:
                tailB = currB
                currB = headA
                
            if tailA and tailB and tailA != tailB:
                return None
