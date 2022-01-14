# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #we follow sentinel approach by making a new node
        #before head and point prev to it
        
        #sentinel node
        sentinel=ListNode(None,head)
        #prev node before the starting of the list
        prev=sentinel
        curr=head
        while curr:
            # if it's a beginning of duplicates sublist 
            # skip all duplicates
            if(curr.next and curr.val == curr.next.val):
                # move till the end of duplicates sublist
                while(curr.next and curr.val==curr.next.val):
                    curr=curr.next
                # skip all duplicates
                prev.next=curr.next
            # otherwise, move predecessor
            else:
                prev = prev.next
            # move forward
            curr=curr.next
            
        #as sentinel is before the list starts
        #sentinel.next points to the starting
        return sentinel.next