"""
Name: Parvez Hossen.
ID: 174049
Assignment No: 01
Programming Language: python

"""

"""

    ***Problem Definition:
                            In computer science, the grid problem is a classic problem that involves finding
    the shortest path between two points on a grid. The grid is typically represented
     as a two-dimensional array, with each cell representing a location on the grid.

     There are two points one is start and another is end point. We have to find the shortest path
     between them. There may have obstackle in a cell that means we cannot traverse over this cell.

"""


"""
This is for input. We can take input from file or manually. It is a sample input figured in problem description.
Here, 1 means we can move this cell. 'S' indicates start from here and 'E' is goal position. 'X' represents obstacle that
means we can not move this cell.
"""


g=[
        ['S','X',1,1,1,1,1,'X',1,1,1,1,1,1,1],
        [1,'X',1,1,1,'X',1,1,1,1,1,1,1,1,1],
        [1,1,1,'X',1,'X',1,1,1,'X','X','X','X','X','X'],
        [1,1,1,'X',1,1,1,'X',1,1,'X',1,1,1,1],
        [1,1,1,'X',1,1,'X',1,1,1,1,1,'X',1,'E']
    ]

"""
    In a grid, start and end positoin may different or same cell or may unspecific cell.
    Firstly, we have to find out start and end position.
    Here, start and end represent those position.
"""
start=tuple()
end=tuple()
"""
    This loop below is used for finding start and end position.
"""
for i in range(len(g)):
  for j in range(len(g[0])):
    if g[i][j]=='S':
      start=(i,j)
    elif g[i][j]=='E':
      end=(i,j)

visited=list() # A list is used for remembering visited cell.
resPath=[0] #This is for containing final shortest path.
expNode=[1] #Number of Nodes expanded during traversal
visitNode=[0]

"""
BFS (Breadth-First Search) is an algorithm for traversing or searching a tree or graph data structure. It involves 
starting at the root node and exploring all the neighboring nodes at the present depth level before moving on to 
the nodes at the next depth level.
"""
def bfs(start, goal):
    checker = False
    queue = [(start, [start])] # queue data structure for first in first out.
    while len(queue)>0:
        node,path=queue.pop(0)
        visitNode[0]+=1
        for i in [(0,1),(1,0),(0,-1),(-1,0)]: # we can move only four directions (up, down, left, right)
            ni=node[0]+i[0]
            nj=node[1]+i[1]
            temp=path.copy()
            if 0<=ni<len(g) and 0<=nj<len(g[0]) and g[ni][nj]!='X' and (ni,nj) not in visited: # check if it is the out of grid or a grid cell have obstacle
                expNode[0] += 1
                if (ni,nj) == goal: # check weather it is goal cell
                    resPath[0] = path+[(ni,nj)]
                    checker=True
                    break
                temp.append((ni,nj))
                queue.append(((ni,nj), temp))
                visited.append((ni,nj))
        if checker==True:break


bfs(start,end)
print("Path: ",resPath[0])
print("Steps: ",len(resPath[0])-1)
print("Visited Node: ",visitNode[0])
print("Expanded Node: ",expNode[0] )

#----------------------------------------Output of bfs traversal----------------------------------------------
"""
Path:  [(0, 0), (1, 0), (2, 0), (2, 1), (2, 2), (1, 2), (1, 3), (1, 4), (2, 4), (3, 4), 
        (3, 5), (3, 6), (2, 6), (2, 7), (2, 8), (3, 8), (3, 9), (4, 9), (4, 10), (4, 11), (3, 11), 
        (3, 12), (3, 13), (3, 14), (4, 14)]
Steps:  24
Visited Node:  56
Expanded Node:  58
"""
#----------------------------------------End bfs traversal---------------------------------------------------




#----------------------------------------------------------------------------------------------------------------
#-----------------Depth first search search over a grid------------------------



"""
Now, for finding shortest path, we may use Depth first Search algorithm. DFS is an algorithm 
for traversing a tree or graph data structure. It involves starting at the root node and 
exploring as far as possible along each branch before backtracking.
Since, We have to find shortest path, we may use backtracking in addition.
"""
g=[  #This is for input. We can take input from file or manually. It is a sample input.
    ['S','X',1,1,1,1,1,'X',1,1,1,1,1,1,1],
    [1,'X',1,1,1,'X',1,1,1,1,1,1,1,1,1],
    [1,1,1,'X',1,'X',1,1,1,'X','X','X','X','X','X'],
    [1,1,1,'X',1,1,1,'X',1,1,'X',1,1,1,1],
    [1,1,1,'X',1,1,'X',1,1,1,1,1,'X',1,'E']
]
"""
In a grid, start and end positoin may different or same cell or may unspecific cell.
Firstly, we have to find out start and end position.
Here, start and end represent those position.
"""
start=tuple()
end=tuple()

"""
This loop below is used for finding start and end position.
"""
for i in range(len(g)):
  for j in range(len(g[0])):
    if g[i][j]=='S':
      start=(i,j)
    elif g[i][j]=='E':
      end=(i,j)

visited=list() # A list is used for remembering visited cell.
resPath=[9 for i in range(9999)] #This is for containing final shortest path.
expNode=[1] #Number of Nodes expanded during traversal.
visitNode=[0]


def dfs(node, end,visit): # Depth First Search Function
    global resPath # contain the shortest path only
    if node[0]==end: # if we find goal position then check if it is the shortest with before
        if len(resPath)>len(node[1]):
            resPath=node[1][:]
            return
    visitNode[0]+=1
    for i in [(1,0),(-1,0),(0,1),(0,-1)]: # we can move only four directions (up, down, left, right)
        ni=node[0][0]+i[0] #making new position
        nj=node[0][1]+i[1]
        temp=node[1].copy()
        #print(temp)
        if 0<=ni<len(g) and 0<=nj<len(g[0]) and (ni,nj) not in visited and g[ni][nj]!='X': # check if it is the out of grid or a grid cell have obstacle
            expNode[0]+=1
            visited.append((ni,nj))
            temp.append((ni,nj))
            dfs(((ni,nj),node[1]+[(ni,nj)]),end,visit)
            visited.remove((ni,nj))

dfs((start,[start]),end,0)
print("Path: ",resPath)
print("Steps: ",len(resPath)-1)
print("Visited Node: ",visitNode[0])
print("Expanded Node: ",expNode[0])

#-----------------------------------------Output of dfs traversal--------------------------------------------
"""
Path: [(0, 0), (1, 0), (2, 0), (2, 1), (2, 2), (1, 2), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (1, 6), 
        (2, 6), (2, 7), (2, 8), (3, 8), (4, 8), (4, 9), (4, 10), (4, 11), (3, 11), (3, 12), (3, 13), (4, 13), (4, 14)]
Steps:  24
Visited Node:  218794
Expanded Node:  218800
"""
#------------------------------------------End dfs traversal-------------------------------------------------

