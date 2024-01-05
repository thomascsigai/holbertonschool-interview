#!/usr/bin/python3

'''
determines if all the boxes can be opened
'''


def canUnlockAll(boxes):
    boxesOpened = [False] * len(boxes)
    boxesOpened = openBox(0, boxes, boxesOpened)

    return all(boxesOpened)


def openBox(boxIndex, boxes, boxesOpened):
    if boxIndex < len(boxesOpened) and not boxesOpened[boxIndex]:
        boxesOpened[boxIndex] = True
        for var in boxes[boxIndex]:
            openBox(var, boxes, boxesOpened)

    return boxesOpened
