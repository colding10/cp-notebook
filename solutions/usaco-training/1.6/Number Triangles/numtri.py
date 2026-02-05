'''
ID: colindi1
LANG: PYTHON3
TASK: numtri
'''

# for each row, go through each number
# add it to the highest one above it (two choices)
# this is much faster than doing dfs or bfs
# this can find the maximum "route product" to any point
# just find the maximum of the bottom row

with open('numtri.in', 'r') as file:
    number_of_rows = int(file.readline())

    triangle_rows = [list(map(int, row.replace('\n', '').split())) for row in file.readlines()]


for index, line in enumerate(triangle_rows):
    if index != 0:
        for number_index, number in enumerate(line):
            if number_index == 0:
                triangle_rows[index][number_index] = triangle_rows[index][number_index] + triangle_rows[index - 1][number_index]
                continue
            elif number == line[-1]:
                triangle_rows[index][number_index] = triangle_rows[index][number_index] + triangle_rows[index - 1][number_index - 1]
            if index != number_of_rows - 1:
                if triangle_rows[index][number_index] >= triangle_rows[index][number_index - 1]:
                    triangle_rows[index + 1][number_index] += triangle_rows[index][number_index]
                else:
                    triangle_rows[index + 1][number_index] += triangle_rows[index][number_index - 1]

out = str(max(triangle_rows[-1]))

with open('numtri.out', 'w') as file:
    file.write(out + '\n')