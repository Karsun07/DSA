# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.i = 0

    def fun(self, start, end, pre, ino):
        if start > end:
            return None

        node = TreeNode(pre[self.i])
        root = pre[self.i]
        self.i += 1

        pos = -1
        for j in range(start, end + 1):
            if ino[j] == root:
                pos = j
                break

        node.left = self.fun(start, pos - 1, pre, ino)
        node.right = self.fun(pos + 1, end, pre, ino)

        return node

    def buildTree(self, preorder: list[int], inorder: list[int]) -> TreeNode | None:
        self.i = 0
        n = len(preorder)

        return self.fun(0, n - 1, preorder, inorder)
        