# -*- coding: utf-8 -*-


class Node(object):

    def __init__(self, x):
        super(Node, self).__init__()
        self.digit = int(x)
        self.next = None


class LinkList(object):

    def __init__(self, nodes):
        self.head = None

        if isinstance(nodes, (list, tuple)):
            cur = None
            for node in nodes:
                try:
                    cur.next = Node(node)
                    cur = cur.next
                except AttributeError:
                    cur = Node(node)
                    self.head = cur
        elif isinstance(nodes, Node):
            self.head = nodes

    def toList(self):
        ret = []
        cur = self.head
        while cur is not None:
            ret.append(cur.digit)
            cur = cur.next
        return ret


class Solution(object):

    def __init__(self):
        self.c = 0

    def addTwoNumbers(self, l1, l2):
        result = None
        res_cur = result
        cur_1 = LinkList(l1).head
        cur_2 = LinkList(l2).head
        try:
            while True:
                d = Node(self.sum(cur_1.digit, cur_2.digit))
                try:
                    res_cur.next = d
                    res_cur = res_cur.next
                except AttributeError:
                    result = d
                    res_cur = result
                cur_1 = cur_1.next
                cur_2 = cur_2.next
        except AttributeError:
            if cur_1 is not None:
                res_cur.next = cur_1
            else:
                #  for some reason
                #  这个操蛋的 LeetCode 的表现和本地的解释器完全不同
                #  在这里总是会抛出 AttributeError
                #  但是此处已经证明，不会对 None 引用进行操作
                #  所以，FTL
                res_cur.next = cur_2
            return LinkList(result).toList()

    def sum(self, a, b):
        num = a + b + self.c
        if num > 9:
            self.c = 1
        else:
            self.c = 0
        return num % 10


