
"""
Name: Parvez Hossen.
ID: 174049
Assignment No: 02
Programming Language: python
"""

"""

    ***Problem Definition:
                            Write a code segment to solve the same grid-based path finding problem as given in 
    Assignment-1, but this time using the following 3 different search strategies -- the next visiting node will 
    be the node N which has the lowest i) g cost, ii) h cost, or iii) g+h cost, where g represents the actual path 
    cost from I to N, and h represents the "estimated" cheapest path cost from N to G. Note that from each cell you 
    can only move to any of it's 8 neighboring cells (up, down, left, right, and immediate diagonal 4 cells). The 
    cost for each move to up, down, left, or right is 1; and 1.5 to any immediate diagonal cell. You have to show the
     path (from I to G), path cost (number of steps), total explored and total visited cells in the output for each of 
     those 3 strategies. Remember that for 1st and 3rd strategies, you shouldn't stop the search as soon as  G is 
     encountered but there still exist other nodes/cells waiting in the fringe to be expanded with lower node cost.

"""

# ----------------------------Dijkstra Algorithm-----------------------------
from heapq import heappop, heappush

def dijkstra(grid, start, goal):
    rows = len(grid)
    cols = len(grid[0])
    actual_cost = [[float('inf')] * cols for _ in range(rows)]  # The cost to reach each node
    actual_cost[start[0]][start[1]] = 0  # The cost to reach the start node is 0
    queue = [(0, (start[0], start[1]), [(0, 0)])]  # A priority queue of the nodes to visit
    visited = set()  # A set to track the nodes that have been visited
    exp = 0

    # The directions to move in the grid
    # (up, down, left, right, up-left, up-right, down-left, down-right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]
    while queue:
        # Get the node with the lowest cost
        current_cost, (row, col), path = heappop(queue)
        # Mark the node as visited
        visited.add((row, col))

        # Check the neighbors of the node
        for direction in directions:
            new_row = row + direction[0]
            new_col = col + direction[1]
            # Calculate the new position and cost
            new_cost = current_cost + (1.5 if row != new_row and col != new_col else 1)

            # Make sure the new position is within the grid and not blocked
            if (new_row >= 0 and new_row < rows and new_col >= 0 and new_col < cols
                    and grid[new_row][new_col] != 'X' and (new_row, new_col) not in visited):
                # Update the cost if it is lower than the current cost
                if new_cost < actual_cost[new_row][new_col]:
                    exp += 1
                    actual_cost[new_row][new_col] = new_cost
                    # Add the new position to the queue
                    heappush(queue, (new_cost, (new_row, new_col), path + [(new_row, new_col)]))

                    # If we have reached the goal, return the cost
                    if grid[new_row][new_col] == 'E':
                        print()
                        print("Path: ", path + [(new_row, new_col)])
                        print("Steps: ", len(path), "Path cost: ", actual_cost[new_row][new_col])
                        print("Visited: ", len(visited))
                        print("Expanded: ", exp)


"""
This is for input. We can take input from file or manually. It is a sample input figured in problem description.
Here, 1 means we can move this cell. 'S' indicates start from here and 'E' is goal position. 'X' represents obstacle that
means we can not move this cell.
"""

# Example usage
grid = [
    ['S', 'X', 1, 1, 1, 1, 1, 'X', 1, 1, 1, 1, 1, 1, 1],
    [1, 'X', 1, 1, 1, 'X', 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 'X', 1, 'X', 1, 1, 1, 'X', 'X', 'X', 'X', 'X', 'X'],
    [1, 1, 1, 'X', 1, 1, 1, 'X', 1, 1, 'X', 1, 1, 1, 1],
    [1, 1, 1, 'X', 1, 1, 'X', 1, 1, 1, 1, 1, 'X', 1, 'E']
]

"""
    This loop below is used for finding start and end position.
"""
for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == 'S':
            start = (i, j)
        elif grid[i][j] == 'E':
            goal = (i, j)

dijkstra(grid, start, goal)

# -------------------------------------Output of dijkstra Search---------------------------------------------------
"""
Path:  [(0, 0), (1, 0), (2, 1), (2, 2), (1, 3), (2, 4), (3, 5), (3, 6), (4, 7), (4, 8), (4, 9), (4, 10), 
        (4, 11), (3, 12), (3, 13), (4, 14)]

Steps:  15 Path cost:  18.5
Visited:  53
Expanded:  56
"""
# -------------------------------------End of dijkstra Search------------------------------------------------------




#---------------------------------------Heuristic Search------------------------------------------------
"""
Heuristic search is a type of search algorithm that uses heuristics, or "rules of thumb",
to guide the search towards the goal. The heuristic function estimates the cost of reaching the goal from a given node.
"""

import heapq

def heuristic(grid,start,goal):

    que=[(4,0,start,[start])]  # A priority queue of the nodes to visit
    visit=set() # A set to track the nodes that have been visited
    explore=set()
    explore.add(start)

    breaker=False
    while que:
        # Get the node with the lowest cost
        dist,cost,node,path=heapq.heappop(que)
        visit.add(node) # Mark the node as visited

        # The directions to move in the grid
        # (up, down, left, right, up-left, up-right, down-left, down-right)
        for i in [(1,0),(-1,0),(0,1),(0,-1),(-1,-1),(-1,1),(1,-1),(1,1)]:
            # Check the neighbors of the node
            ni=node[0]+i[0]
            nj=node[1]+i[1]
            # Calculate the new position and cost
            # Make sure the new position is within the grid and not blocked
            if 0<=ni<len(grid) and 0<=nj<len(grid[1]) and (ni,nj) not in explore:
                explore.add((ni,nj))
                if (ni,nj)==goal:
                    cost=cost + (1.5 if (ni != node[0] and nj != node[1]) else 1)
                    print("Path: ",path+[(ni,nj)])
                    print("Steps: ",len(path),"Path cost: ",cost)
                    print("Visited: ",len(visit),"Explore: ",len(explore))
                    breaker=True
                    break
                else:
                    # Add the new position to the queue
                    heapq.heappush(que,(abs(goal[0]-ni)+abs(goal[1]-nj),(cost+(1.5 if (ni!=node[0] and nj!=node[1]) else 1)),(ni,nj),path+[(ni,nj)]))
        if breaker:break


grid = [
    ['S', 'X', 1, 1, 1, 1, 1, 'X', 1, 1, 1, 1, 1, 1, 1],
    [1, 'X', 1, 1, 1, 'X', 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 'X', 1, 'X', 1, 1, 1, 'X', 'X', 'X', 'X', 'X', 'X'],
    [1, 1, 1, 'X', 1, 1, 1, 'X', 1, 1, 'X', 1, 1, 1, 1],
    [1, 1, 1, 'X', 1, 1, 'X', 1, 1, 1, 1, 1, 'X', 1, 'E']
]
"""
    This loop below is used for finding start and end position.
"""
for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j]=='S':
            start=(i,j)
        elif grid[i][j]=='E':
            goal=(i,j)
heuristic(grid, start,goal)

#----------------------------------------Output of Heuristic Search---------------------------------------------------
"""
Path:  [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4), (4, 5), (4, 6), (4, 7), (4, 8), (4, 9), (4, 10), (4, 11),
        (4, 12), (4, 13), (4, 14)]
        
Steps:  14 Path cost:  16.0
Visited Node:  14 
Explored Node:  38
"""
#-----------------------------------------End of Heuristic Search-----------------------------------------------------


import heapq

# ----------------------------------------g+h cost--------------------------------------------------------------
"""
In this section, we have to follow this procedure:
    *Initialize the cost to reach each node to infinity, and the cost to reach the start node to 0.
    *Initialize the estimated total cost to reach the goal for each node to infinity, and the estimated total
        cost for the start node to the cost to reach it plus the heuristic function value for the start node.
    *Create a priority queue of nodes to visit, initialized with the start node.
    *Create a set to track the nodes that have been visited.
    *While the queue is not empty:
        *Pop the node with the lowest estimated total cost from the queue.
        *If the node is the goal, return the cost to reach it.
        *Mark the node as visited.
        *For each of the node's neighbors:
            *Calculate the cost to reach the neighbor.
            *If the cost is lower than the current cost to reach the neighbor, update the cost and the estimated total cost.
            *If the neighbor has not been visited, add it to the queue.
        *If the queue is empty and the goal has not been reached, return infinity.
"""

def ActualAndHeuristic(grid, start, goal):
    rows = len(grid)  # length of rows
    cols = len(grid[0])  # length of columns
    actual_cost = [[float('inf')] * cols for _ in range(rows)]  # The cost to reach each node
    actual_cost[start[0]][start[1]] = 0  # The cost to reach the start node is 0

    estimate_cost = [[float('inf')] * cols for _ in
                     range(rows)]  # The total cost(actual and heuristic) of each node
    estimate_cost[start[0]][start[1]] = actual_cost[start[0]][start[1]] + abs(start[0] - goal[0]) + abs(
        start[1] - goal[1])

    que = [(estimate_cost[start[0]][start[1]], 0, (start), [start])]  # A priority queue of the nodes to visit
    visited = set()  # A set to track the nodes that have been visited

    visitNode = 0
    exploreNode = 1
    while que:

        est_cost, steps, node, path = heapq.heappop(que)  # Get the node with the lowest cost
        visitNode += 1
        visited.add(node)  # Mark the node as visited

        # The directions to move in the grid  (up, down, left, right, up-left, up-right, down-left, down-right)
        for i in [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1)]:
            ni = node[0] + i[0]
            nj = node[1] + i[1]
            # Make sure the new position is within the grid and not blocked
            if 0 <= ni < rows and 0 <= nj < cols and grid[ni][nj] != 'X' and (ni, nj) not in visited:
                new_cost = actual_cost[node[0]][node[1]] + (1.5 if ni != node[0] and nj != node[1] else 1)
                # Update the cost if it is lower than the current cost
                if new_cost < actual_cost[ni][nj]:
                    exploreNode += 1
                    actual_cost[ni][nj] = new_cost
                    # Calculate the new position and cost
                    estimate_cost[ni][nj] = new_cost + abs(ni - goal[0]) + abs(nj - goal[1])
                    # Add the new position to the queue
                    heapq.heappush(que, (estimate_cost[ni][nj], steps + 1, (ni, nj), path + [(ni, nj)]))
                    if (ni, nj) == goal:
                        print("Path: ", path + [(ni, nj)])
                        print("Steps:", steps + 1, "Path cost: ", actual_cost[ni][nj])
                        print("Visited: ", visitNode)
                        print("Explored: ", exploreNode)

grid = [
    ['S', 'X', 1, 1, 1, 1, 1, 'X', 1, 1, 1, 1, 1, 1, 1],
    [1, 'X', 1, 1, 1, 'X', 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 'X', 1, 'X', 1, 1, 1, 'X', 'X', 'X', 'X', 'X', 'X'],
    [1, 1, 1, 'X', 1, 1, 1, 'X', 1, 1, 'X', 1, 1, 1, 1],
    [1, 1, 1, 'X', 1, 1, 'X', 1, 1, 1, 1, 1, 'X', 1, 'E']
]
"""
    This loop below is used for finding start and end position.
"""
for i in range(len(grid)):
    for j in range(len(grid[0])):
        if grid[i][j] == 'S':
            start = (i, j)
        elif grid[i][j] == 'E':
            goal = (i, j)

ActualAndHeuristic(grid, start, goal)

# --------------------------------------Output of g+h cost----------------------------------------------
"""
Path:  [(0, 0), (1, 0), (2, 1), (2, 2), (1, 3), (2, 4), (3, 5), (3, 6), (4, 7), (4, 8), (4, 9), (4, 10), 
        (4, 11), (3, 12), (4, 13), (4, 14)]

Steps: 15 Path cost:  18.5
Visited:  33
Explored:  43
"""
# --------------------------------------End g+h cost----------------------------------------------------



