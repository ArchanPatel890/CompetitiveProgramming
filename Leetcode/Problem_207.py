from typing import List
from collections import defaultdict, deque

class DirectedGraph:
    def __init__(self, numCourses):
        self.graph = defaultdict(list)
        self.V = numCourses
    
    def addEdge(self, u, v):
        self.graph[u].append(v)
    
    def computeInDegrees(self):
        self.inDegrees = [0] * self.V
        for u in range(self.V):
            if u in self.graph:
                for v in self.graph[u]:
                    self.inDegrees[v] += 1
    
    def topologicalSort(self) -> list:
        self.queue = deque()
        for u in range(self.V):
            if self.inDegrees[u] == 0:
                self.queue.append(u)
        
        count = 0
        topologicalOrder = []
        
        while len(self.queue) != 0:
            u = self.queue.popleft()
            topologicalOrder.append(u)
            
            if u in self.graph:
                for i in self.graph[u]:
                    self.inDegrees[i] -= 1
                    if self.inDegrees[i] == 0:
                        self.queue.append(i)
                
            count += 1
        
        if count != self.V:
            return None
        
        return topologicalOrder 
    
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = DirectedGraph(numCourses)
        for u, v in prerequisites:
            graph.addEdge(u, v)
        
        graph.computeInDegrees()
        topologicalOrder = graph.topologicalSort()
    
        if not topologicalOrder:
            return False
        return True