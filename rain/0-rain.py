#!/usr/bin/python3
"""
This module provides a function to calculate the amount of water retained
between walls after it rains. The walls are represented as a list of
non-negative integers, with each integer indicating the height of a wall.
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.

    Args:
        walls (list): List of non-negative integers representing wall heights.

    Returns:
        int: Total units of water retained.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left_max = [0] * n
    right_max = [0] * n

    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Fill right_max array
    right_max[-1] = walls[-1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate water retained
    water_retained = 0
    for i in range(n):
        water_retained += max(0, min(left_max[i], right_max[i]) - walls[i])

    return water_retained
