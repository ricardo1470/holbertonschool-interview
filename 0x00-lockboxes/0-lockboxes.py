#!/usr/bin/python3
""" number of locked boxes """



def canUnlockAll(boxes):
    """ boxes """

    keys = {0}
    added = False
    while not added:
        updated = False
        for i in range(len(boxes)):
            if i in keys:
                for key in boxes[i]:
                    if key not in keys:
                        updated = True
                    keys.add(key)
        added = True if not updated else False
    return (len(keys) == len(boxes))
