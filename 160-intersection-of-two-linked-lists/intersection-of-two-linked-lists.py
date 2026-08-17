# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode | None:
        if not headA or not headB:
            return None
            
        # Initialize two tracking pointers at the head of each list
        pointerA = headA
        pointerB = headB
        
        # Traverse until both pointers meet at the exact same node
        while pointerA != pointerB:
            # Move pointer A forward, or redirect to Head B if it hits the end
            pointerA = pointerA.next if pointerA else headB
            
            # Move pointer B forward, or redirect to Head A if it hits the end
            pointerB = pointerB.next if pointerB else headA
            
        # Returns either the intersection node or None if they never meet
        return pointerA
