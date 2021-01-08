#!/usr/bin/python3
""" there is a single character H.
    Your text editor can execute only two operations in this file:
    Copy All and Paste. Given a number n, write a method
    that calculates the fewest number of operations needed to result
    in exactly n H characters in the file. """


def minOperations(n):
    """ If n is impossible to achieve, return 0 """
    current = 1
    count = 0

    if (n < 2 or type(n) is not int):
        return (0)

    while (current < n):
        res = n - current

        if (res % current == 0):
            buffer = current
            current += buffer
            count += 2
        else:
            current += buffer
            count = count + 1

    return (count)
