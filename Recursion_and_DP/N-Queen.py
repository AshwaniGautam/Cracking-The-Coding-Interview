import sys


'''
    INPUT : N (integer)
    OUTPUT: Total number of solution
    Time Com.: O(N!)
    Space Com.: O(N^2)  '''


def column_check(col):
    for i in xrange(N):
        if chessboard[i][col]:
            return False
    return True


def row_check(row):
    for i in xrange(N):
        if chessboard[row][i]:
            return False
    return True


def diagonal_check(row, col):

    i, j, k, l = row, col, row, col

# Checking left upper diagonal
    while i >= 0 and j >= 0:
        if chessboard[i][j]:
            return False
        i -= 1
        j -= 1
# Checking left lower diagonal        
    while k < N and l >= 0:
        if chessboard[k][l]:
            return False
        k += 1
        l -= 1
        
    return True


def check(row, col):

    if row_check(row) and column_check(col) and diagonal_check(row, col):
        return True
    return False


def place_queen(row, col):
    chessboard[row][col] = 1


def remove_queen(row, col):
    chessboard[row][col] = 0


def solve(col):
    global total
    if col >= N:
        total += 1
        #print chessboard       Uncomment this line to print all valid solutions
        return 1

    for i in xrange(N):
        if check(i, col):
            place_queen(i, col)
            solve(col+1)
            remove_queen(i, col)

    return 0


for arg in sys.argv:
    N = int(sys.argv[1])

chessboard = []
for ite in xrange(N):
    chessboard.append([0] * N)


total = 0
solve(0)
print total
