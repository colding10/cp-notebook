'''
ID: colindi1
LANG: PYTHON3
TASK: preface
'''

import math

with open('preface.in', 'r') as file:
    N = int(file.readline().strip())

def integerToRoman(number):
    romansDict = \
        {
            1: "I",
            5: "V",
            10: "X",
            50: "L",
            100: "C",
            500: "D",
            1000: "M",
        }
  
    div = 1
    while number >= div:
        div *= 10
  
    div /= 10
  
    res = ""
  
    while number:
  
        # main significant digit extracted
        # into lastNum
        lastNum = int(number / div)
  
        if lastNum <= 3:
            res += (romansDict[div] * lastNum)
        elif lastNum == 4:
            res += (romansDict[div] +
                        romansDict[div * 5])
        elif 5 <= lastNum <= 8:
            res += (romansDict[div * 5] +
            (romansDict[div] * (lastNum - 5)))
        elif lastNum == 9:
            res += (romansDict[div] +
                        romansDict[div * 10])
  
        number = math.floor(number % div)
        div /= 10
          
    return res

def romanCharacterToNumber(character):
    romansDict = \
        {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
    
    return romansDict[character]

letters_printed = []
unique_characters_printed = []

for integer_page_number in range(1, N + 1):
    roman_numbers = integerToRoman(integer_page_number)
    roman_characters = list(roman_numbers)

    letters_printed += roman_characters
    unique_characters_printed += [char for char in roman_characters if char not in unique_characters_printed]

unique_characters_printed.sort(key=romanCharacterToNumber)

out_list = []
for unique_character in unique_characters_printed:
    out_item = f'{unique_character} {letters_printed.count(unique_character)}'
    out_list.append(out_item)

out = '\n'.join(out_list)

with open('preface.out', 'w') as file:
    file.write(out + '\n')