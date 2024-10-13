#!/usr/bin/python3
"""
this script reads stdin line by line and computes metrics
"""
import sys


def printS(fileSize, statusDict):
    """ print """
    print("File size: {:d}".format(fileSize))
    for key in sorted(statusDict.keys()):
        if statusDict[key] != 0:
            print(
                "{}: {:d}".format(
                    key, statusDict[key]
                )
            )


if __name__ == "__main__":
    i = 0
    statusDict = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }
    fileSize = 0
    try:
        for line in sys.stdin:
            keywords = line.split()
            if len(keywords) >= 2:
                if keywords[-2] in statusDict.keys():
                    statusDict[keywords[-2]] += 1
                fileSize += int(keywords[-1])
                i += 1
                if not i % 10:
                    printS(fileSize, statusDict)
        printS(fileSize, statusDict)
    except KeyboardInterrupt:
        printS(fileSize, statusDict)
        raise
