# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def fun(self, p, q):

        if not p and not q:
            return True

        if (p and not q) or (q and not p):
            return False

        if p.val != q.val:
            return False

        x = self.fun(p.left, q.left)
        y = self.fun(p.right, q.right)

        return x and y


    def isSubtree(self, root: Optional[TreeNode],
                  subRoot: Optional[TreeNode]) -> bool:

        if not subRoot:
            return True

        if not root:
            return False

        if root.val == subRoot.val:
            if self.fun(root, subRoot):
                return True

        if self.isSubtree(root.left, subRoot):
            return True

        if self.isSubtree(root.right, subRoot):
            return True

        return False