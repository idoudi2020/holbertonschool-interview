#!/usr/bin/python3
""" method that determines valid UTF-8 encoding """


def EightBits(integer):
    """ A function that:
    converts an integer to its binary representation """
    binary = bin(integer)[2:]
    add = '0' * (8 - len(binary))
    return add + binary


def validUTF8(data):
    """ method that checks a valid UTF-8 """
    i = 0
    while i < len(data):
        if EightBits(data[i])[0] == '0':
            i += 1
        elif (EightBits(data[i])[:3] == '110' and i + 1 < len(data) and
                EightBits(data[i + 1])[:2] == '10'):
            i += 2
        elif (EightBits(data[i])[:4] == '1110' and i + 2 < len(data) and
                EightBits(data[i + 1])[:2] == '10' and
                EightBits(data[i + 1])[:2] == '10'):
            i += 3
        elif (EightBits(data[i])[:5] == '11110' and i + 3 < len(data) and
                EightBits(data[i + 1])[:2] == '10' and
                EightBits(data[i + 2])[:2] == '10' and
                EightBits(data[i + 3])[:2] == '10'):
            i += 4
        else:
            return False
    return True
