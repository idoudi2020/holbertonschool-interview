#!/usr/bin/python3
"Special module that contain N queen puzzle challenge"
import sys


def pos_qn_nqueen(board, pos_qn):
    "Search the queens puzzle"
    for x in board:
        if x[1] == pos_qn[1]:
            return False
        if (x[0] + x[1]) == (pos_qn[0] + pos_qn[1]):
            return False
        if (x[0] - x[1]) == (pos_qn[0] - pos_qn[1]):
            return False
    return True


def search_queens(x, N, board):
    "Search the queens"
    if (x == N):
        print(board)
    else:
        for y in range(N):
            pos_qn = [x, y]
            if pos_qn_nqueen(board, pos_qn):
                board.append(pos_qn)
                search_queens(x + 1, N, board)
                board.remove(pos_qn)


if __name__ == '__main__':
    "Search the queens"
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        sys.exit(1)
    N = int(sys.argv[1])
    if (N < 4):
        print("N must be at least 4")
        sys.exit(1)
    lst = []
    search_queens(0, N, lst)