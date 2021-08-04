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
    else:
        return [[1] + [x + y for x, y in zip(pascal_triangle(n - 1),
        pascal_triangle(n - 1)[1:])] + [1] for n in range(1, n + 1)]
