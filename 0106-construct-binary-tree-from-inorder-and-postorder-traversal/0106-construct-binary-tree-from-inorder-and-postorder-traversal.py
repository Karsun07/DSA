# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.i = 0

    def fun(self, start, end, ino, post):
        if start > end:
            return None

        node = TreeNode(post[self.i])

        pos = -1

        for x in range(start, end + 1):
            if ino[x] == post[self.i]:
                pos = x
                break

        if pos == -1:
            return None

        self.i -= 1

        node.right = self.fun(pos + 1, end, ino, post)

        node.left = self.fun(start, pos - 1, ino, post)

        return node

    def buildTree(self, inorder: list[int], postorder: list[int]) -> TreeNode | None:
        n = len(inorder)

        self.i = n - 1

        return self.fun(0, n - 1, inorder, postorder)