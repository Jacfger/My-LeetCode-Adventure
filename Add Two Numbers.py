# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def makeList(list):
    num_list = None
    for num in list[::-1]:
        try:
            num_list.next = ListNode(num)
            num_list = num_list.next
        except:
            num_list = ListNode(num)
            res = num_list
    return num_list
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        curr_digit_l1 = l1
        curr_digit_l2 = l2
        succeed = 0
        sum = None
        res = None
        while curr_digit_l1 and curr_digit_l2:
            try:
                sum.next = ListNode()
                sum = sum.next
            except:
                sum = ListNode()
                res = sum
            x = curr_digit_l1.val + curr_digit_l2.val + succeed
            if x >= 10:
                sum.val = x - 10
                succeed = 1
            else:
                sum.val = x
                succeed = 0
            curr_digit_l1 = curr_digit_l1.next
            curr_digit_l2 = curr_digit_l2.next
        if curr_digit_l1 or curr_digit_l2:
            while curr_digit_l1:
                sum.next = ListNode()
                sum = sum.next
                x = curr_digit_l1.val + succeed
                if x >= 10:
                    sum.val = x - 10
                    succeed = 1
                else:
                    sum.val = x
                    succeed = 0
                curr_digit_l1 = curr_digit_l1.next
            while curr_digit_l2:
                sum.next = ListNode()
                sum = sum.next
                sum.val = curr_digit_l2.val + succeed
                if x >= 10:
                    sum.val = x - 10
                    succeed = 1
                else:
                    sum.val = x
                    succeed = 0
                curr_digit_l2 = curr_digit_l2.next
        if succeed == 1:
            sum.next = ListNode()
            sum = sum.next
            sum.val = 1
        return res

print(makeList([2,3,4]).val)