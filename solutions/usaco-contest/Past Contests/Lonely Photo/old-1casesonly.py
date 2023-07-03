# used usaco solution and reimplemented in python 

import sys

N = sys.stdin.readline().strip()
cows_string = sys.stdin.readline().strip()

cows = list(cows_string)

lonely_picture_count = -1

for starting_index in range(len(cows)):
    for ending_index in range(starting_index, len(cows)):
        substring = cows[starting_index:ending_index + 1]

        if len(substring) >= 3 and substring.count('G') == 1 or substring.count('H') == 1:
            lonely_picture_count += 1
            break



print(lonely_picture_count)