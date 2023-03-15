


import random

"""
print matrix in grid
"""
def show_table(arr):
    l=[[0]*len(arr) for _ in range(len(arr))]
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i]==j:
                l[i][j]=1
                break
    #print(l)
    for i in l:
        print(i)
def count_attacks(board):
    """
    Returns the number of queens that are
    being threatened by other queens.
    """
    n = len(board)
    attacks = 0
    for i in range(n):
        for j in range(i+1, n):
            if board[i] == board[j] or abs(board[i]-board[j]) == j-i: #checking if two or more queens in same row or column or diagonal
                attacks += 1
    return attacks

def get_best_successor(board):
    """
    Given a board configuration, generates all possible successor states
    by moving each queen to a different row in its own column, and returns
    the one with the lowest number of attacks.
    """
    n = len(board)
    successors = []
    for col in range(n):
        for row in range(n):
            if board[col] != row:
                new_board = board.copy()
                new_board[col] = row
                successors.append(new_board)
    best_successor = min(successors, key=count_attacks) #Return the successor with minimum conflicting
    return best_successor

def local_search(n):
    """
    Solves the N-Queens problem using hill climbing. Starts with a random
    board configuration and generates successors by moving each queen to a
    different row in its own column. If a successor has fewer attacks than
    the current board configuration, it becomes the new current state.
    Stops when no successor has fewer attacks than the current state.
    """
    board = [random.randint(0, n-1) for i in range(n)]
    print(board)
    print("Initial state: ")
    show_table(board)
    while True:
        curr_attacks = count_attacks(board)
        best_successor = get_best_successor(board)
        if count_attacks(best_successor) >= curr_attacks:
            return board
        board = best_successor

# Example usage:
solution = local_search(8)

print("Goal state: ")
show_table(solution)
print(solution)


#-------------------------Output---------------------------------
# for 4 queens..........
"""
Initial state: 
[0, 0, 0, 1]
[1, 0, 0, 0]
[0, 0, 0, 1]
[0, 0, 1, 0]

Output: 
[0, 0, 1, 0]
[1, 0, 0, 0]
[0, 0, 0, 1]
[0, 1, 0, 0]

for 8 queens..........
Initial state: 
[0, 0, 0, 1, 0, 0, 0, 0]
[0, 0, 1, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 0, 1]
[1, 0, 0, 0, 0, 0, 0, 0]
[0, 1, 0, 0, 0, 0, 0, 0]
[0, 1, 0, 0, 0, 0, 0, 0]
[0, 0, 1, 0, 0, 0, 0, 0]
[0, 0, 0, 1, 0, 0, 0, 0]

Output: 
[0, 0, 0, 0, 1, 0, 0, 0]
[0, 0, 1, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 0, 1]
[0, 0, 0, 0, 0, 1, 0, 0]
[0, 0, 0, 1, 0, 0, 0, 0]
[1, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0, 0, 0, 0, 1, 0]
[0, 1, 0, 0, 0, 0, 0, 0]
"""







