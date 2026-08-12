class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
            
        # Step 1: Create interleaved clone nodes
        curr = head
        while curr:
            new_node = Node(curr.val, curr.next)
            curr.next = new_node
            curr = new_node.next
            
        # Step 2: Assign random pointers to clone nodes
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
            
        # Step 3: Separate the original and clone lists
        curr = head
        clone_head = head.next
        while curr:
            clone = curr.next
            curr.next = clone.next
            if clone.next:
                clone.next = clone.next.next
            curr = curr.next
            
        return clone_head

        