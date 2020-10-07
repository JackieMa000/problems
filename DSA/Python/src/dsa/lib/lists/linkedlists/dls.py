from dsa.lib.lists import LinkedList
from dsa.nodes import ListNode


class DoublyLinkedList(LinkedList):
    def __init__(self, head: ListNode):
        super().__init__(head)