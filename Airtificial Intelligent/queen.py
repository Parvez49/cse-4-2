import heapq


def globalcost(m,q):
    confl = 0
    for tu in [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (-1, -1), (1, -1),
               (-1, 1)]:  # checking queen may have in any of them of eight direction
        ni = q[0]
        nj = q[1]
        while True:
            if (0 > ni or ni == len(m)) or (0 > nj or nj == len(m)):  # boundary of matrix
                break
            ni += tu[0]
            nj += tu[1]
            if 0 <= ni and ni < len(m) and 0 <= nj and nj < len(m):
                if m[ni][nj] == 1:
                    confl += 1
    return confl

def fun(m):
    conmx = 100  # for finding maximum confliction queen with other
    mxqun = 100
    for i in range(len(m)):
        for j in range(len(m[0])):
            if m[i][j] == 1:
                confl = 0
                for tu in [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (-1, -1), (1, -1),(-1, 1)]:  # checking queen may have in any of them of eight direction
                    ni = i
                    nj = j
                    while True:
                        if (0 > ni or ni == len(m)) or (0 > nj or nj == len(m)): #boundary of matrix
                            break
                        ni += tu[0]
                        nj += tu[1]
                        if 0 <= ni and ni < len(m) and 0 <= nj and nj < len(m):
                            if m[ni][nj] == 1:
                                confl += 1
                if confl > conmx:
                    conmx = confl
                    mxqun = [i, j] # this is maximum confliction queen
    print(mxqun)

    for pi in [(1, 0), (-1, 0)]: # we can move queen in up or down position in same column

        npi = pi[0]
        npj = pi[1]
        cost = 10000
        while True:
            if npi < 0 or npi == len(mat) or npj < 0 or npj == len(mat):
                break
            npi = pi[0] + mxqun[0] #new queen position
            npj = pi[1] + mxqun[1]
            nmat = mat.copy()
            nmat[mxqun[0]][mxqun[1]] = 1
            nmat[npi][npj] = 1

            ncost = globalcost(nmat)
            if cost < ncost:
                cost = ncost
                minmat = nmat.copy()


#n=input(input())
#mat=[[0]*n for i in range(n)]
mat = [[1, 1, 1, 1],
       [0, 0, 0, 0],
       [0, 0, 0, 0],
       [0, 0, 0, 0]
       ]
mat = [[0, 0, 0, 0],
       [0, 1, 1, 0],
       [1, 1, 0, 0],
       [0, 0, 0, 0]]
visit = list()
visit.append(mat)

h = fun(mat)

