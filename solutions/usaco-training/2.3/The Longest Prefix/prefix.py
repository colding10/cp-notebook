"""
ID: colindi1
LANG: PYTHON3
TASK: prefix
"""

import string
import sys

sys.setrecursionlimit(100000)

fin = open("prefix.in", "r")
fout = open("prefix.out", "w")

primitives, sequence = fin.read().replace("\n", " ").split(".")
primitives = primitives.split()
sequence = sequence.strip().replace(" ", "")

maximum_length = 0
length = 0


values = [None] * len(sequence)
ready = [False] * len(sequence)
expressible = [False] * (len(sequence) + 10)

def recursive(starting_index):
    current_sequence = sequence[starting_index:]
    choices = [recursive(starting_index + len(p)) for p in primitives if current_sequence[:len(p)] == p]
    
    out = max(choices) if choices else starting_index
    
    return out

def dynamic(starting_index):
    if ready[starting_index]:
        return values[starting_index]
    
    current_sequence = sequence[starting_index:]
    
    best = 0
    
    for p in primitives:
        if current_sequence[:len(p)] == p:
            best = max(best, dynamic(starting_index + len(p)))
    
    out = best if best else starting_index

    ready[starting_index] = True
    values[starting_index] = out
    
    return out

def dynamic_table():
    expressible[0] = True
    best = 0
    
    for i in range(len(sequence)):
        if expressible[i]:
            best = i
            
            for p in primitives:
                if sequence[:len(p)] == p:
                    expressible[i + len(p)] = True
                
                    
    return best

fout.write(str(recursive(0)) + "\n")