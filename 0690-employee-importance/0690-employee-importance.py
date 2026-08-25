"""
# Definition for Employee.
class Employee(object):
    def __init__(self, id, importance, subordinates):
    	#################
        :type id: int
        :type importance: int
        :type subordinates: List[int]
        #################
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

from collections import deque

class Solution(object):
    def getImportance(self, employees, id):

        adj = {}
        imp = {}

        # Build graph
        for emp in employees:
            imp[emp.id] = emp.importance
            adj[emp.id] = emp.subordinates


        q = deque()
        q.append(id)

        ans = 0

        while q:

            node = q.popleft()

            ans += imp[node]

            for sub in adj[node]:
                q.append(sub)

        return ans

        