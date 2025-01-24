#!/usr/bin/python3
"""
Rotate 2D Matrix Module
"""


def rotate_2d_matrix(matrix):
    """
    Rotate a 2D matrix 90 degrees clockwise in-place.

    Args:
        matrix (list of list of int): 2D matrix to be rotated.
    """
    n = len(matrix)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            # Save the top element
            temp = matrix[i][j]

            # Move left element to top
            matrix[i][j] = matrix[n - j - 1][i]

            # Move bottom element to left
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]

            # Move right element to bottom
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]

            # Assign temp to right
            matrix[j][n - i - 1] = temp


if __name__ == "__main__":
    """
    Test the rotate_2d_matrix function
    """
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    print("Original Matrix:")
    for row in matrix:
        print(row)

    rotate_2d_matrix(matrix)

    print("\nRotated Matrix:")
    for row in matrix:
        print("[{}]".format(", ".join(map(str, row))))
