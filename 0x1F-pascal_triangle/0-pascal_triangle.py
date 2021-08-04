#!/usr/bin/python3
"""
that returns a list of lists of integers
representing the Pascal’s triangle
"""


def pascal_triangle(n):
    """
    Returns an empty list if n <= 0
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        triangle.append([])
        for j in range(i + 1):
            if j == 0 or j == i:
                triangle[i].append(1)
            else:
                triangle[i].append(triangle[i - 1][j - 1] + triangle[i - 1][j])
    return triangle
