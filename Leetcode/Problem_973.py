from queue import PriorityQueue
from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        if K == 0:
            return []
        
        n = len(points)
        if n == 0:
            return []
        if n == 1:
            return points[0]

        pq = PriorityQueue()
        dist = points[0][0] ** 2 + points[0][1] ** 2
        pq.put((-dist, 0))
        for i in range(1, n):
            dist = points[i][0] ** 2 + points[i][1] ** 2
            if pq.qsize() == K:
                minv, j = pq.get()
                if minv < -dist:
                    pq.put((-dist, i))
                else:
                    pq.put((minv, j))
            else:
                pq.put((-dist, i))
        
        ans = [points[i] for _, i in list(pq.queue)]
        return ans