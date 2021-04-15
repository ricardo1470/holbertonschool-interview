#!/usr/bin/python3
""" a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains. """


def rain(walls):
    """
    - walls is a list of non-negative integers.
    - Return: Integer indicating total amount of rainwater retained.
    - If the list is empty return 0."""
    # To store the maximum water
    max_water = 0
    len_arr = len(walls)

    if len(walls < 0):
        return 0

    for i in range(1, len_arr -1):
        left = walls[i]

        for j in range(i):
            left = max(left,walls[j])
        right = walls[i]

        for j in range(i + 1, len_arr):
            right = max(right, walls[j])

        max_water += (min(left, right) - walls[i])

    return max_water
