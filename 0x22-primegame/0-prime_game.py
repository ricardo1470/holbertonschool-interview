#!/usr/bin/python3
"""
    where x is the number of rounds and nums is an array of n
    Return: name of the player that won the most rounds
    If the winner cannot be determined, return None
    You can assume n and x will not be larger than 10000
    You cannot import any packages in this task
"""


def isWinner(x, nums):
    """
        Return: name of the player that won the most rounds
        If the winner cannot be determined, return None
    """
    if not nums or x < 1:
        return None
    n = max(nums)
    test = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not test[i]:
            continue
        for j in range(i*i, n + 1, i):
            test[j] = False

    test[0] = test[1] = False
    c = 0
    for i in range(len(test)):
        if test[i]:
            c += 1
        test[i] = c

    winner = ''
    player1 = 0
    for n in nums:
        player1 += test[n] % 2 == 1
    if player1 * 2 == len(nums):
        winner = None
    if player1 * 2 > len(nums):
        winner = "Maria"
    else:
        winner = "Ben"
    return winner
