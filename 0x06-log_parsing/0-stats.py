#!/usr/bin/python3
""" script that reads stdin line by
    line and computes metrics:
    - Input format:
    <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
    <status code> <file size>
    -"""
from sys import stdin


status_code = {'200': 0, '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
file_size = 0


def stdin_status():
    """ status code doesn’t
        appear or is not an integer,
        don’t print anything for this status code
    """
    print("File size: {}".format(file_size))
    for key, val in sorted(status_code.items()):
        if val > 0:
            print("{}: {}".format(key, val))

if __name__ == '__main__':
    try:
        for i, line in enumerate(stdin, 1):
            try:
                info = line.split()
                file_size += int(info[-1])
                if info[-2] in status_code.keys():
                    status_code[info[-2]] += 1

            except:
                pass

            if not i % 10:
                stdin_status()

    except KeyboardInterrupt:
        stdin_status()
        raise
    stdin_status()
