from collections import defaultdict 
  
class Graph(): 
    def __init__(self,vertices): 
        self.graph = defaultdict(set) 
        self.V = set()
  
    def addEdge(self,u,v):
        self.V.add(u)
        self.V.add(v)
        self.graph[u].add(v) 
  
    def isCyclicUtil(self, v, visited, recStack): 
  
        # Mark current node as visited and  
        # adds to recursion stack 
        visited[v] = True
        recStack[v] = True
  
        # Recur for all neighbours 
        # if any neighbour is visited and in  
        # recStack then graph is cyclic 
        for neighbour in self.graph[v]: 
            if visited[neighbour] == False: 
                if self.isCyclicUtil(neighbour, visited, recStack) == True: 
                    return True
            elif recStack[neighbour] == True: 
                return True
  
        # The node needs to be poped from  
        # recursion stack before function ends 
        recStack[v] = False
        return False
  
    # Returns true if graph is cyclic else false 
    def isCyclic(self): 
        visited = [False] * 26
        recStack = [False] * 26
        for node in self.V: 
            if visited[node] == False: 
                if self.isCyclicUtil(node,visited,recStack) == True: 
                    return True
        return False
    
    # A recursive function used by topologicalSort 
    def topologicalSortUtil(self,v,visited,stack): 
  
        # Mark the current node as visited. 
        visited[v] = True
  
        # Recur for all the vertices adjacent to this vertex 
        for i in self.graph[v]: 
            if visited[i] == False: 
                self.topologicalSortUtil(i,visited,stack) 
  
        # Push current vertex to stack which stores result 
        stack.insert(0,v) 
  
    # The function to do Topological Sort. It uses recursive  
    # topologicalSortUtil() 
    def topologicalSort(self): 
        # Mark all the vertices as not visited 
        visited = [False] * 26
        stack =[] 
  
        # Call the recursive helper function to store Topological 
        # Sort starting from all vertices one by one 
        for i in self.V: 
            if visited[i] == False: 
                self.topologicalSortUtil(i,visited,stack) 
  
        # Print contents of the stack 
        return stack 
  

def solve(grid, R, C, letters):
    G = Graph([c for c in range(0, 27)])
    for i in range(1, R):
        for j in range(0, C):
            if (grid[i][j] != grid[i-1][j]):
                letters.add(grid[i][j])
                letters.add(grid[i-1][j])
                G.addEdge(ord(grid[i][j])-ord('A'), ord(grid[i-1][j])-ord('A'))
    if G.isCyclic():
        return -1
    else:
        order = [chr(i + ord('A')) for i in G.topologicalSort()]
        for letter in letters:
            if letter not in order:
                order.append(letter)
        return "".join(order)


num_test_cases = int(input())
for case in range(num_test_cases):
    R, C = list(map(int, input().split()))  
    grid = [[0 for _ in range(C)] for _ in range(R)]
    letters = set()
    for i in range(0, R):
        row = input()
        for j in range(0, C):
            grid[i][j] = row[j]
            letters.add(row[j])
    ans = solve(grid, R, C, letters)
    print("Case #{}: {}".format(case+1, ans))