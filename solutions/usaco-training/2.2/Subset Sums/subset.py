'''
ID: colindi1
LANG: PYTHON3
TASK: subset
'''

# from itertools import product, tee, filterfalse

with open('subset.in', 'r') as file:
    N = int(file.readline().strip())

# def partition(pred, iterable):
#     t1, t2 = tee(iterable)
#     return filterfalse(pred, t1), filter(pred, t2)

# def splitList(a_list):
#     out = []

#     for split_index in range(len(a_list)):
#         before = a_list[:split_index]
#         after = a_list[split_index:]

#         if before and after:
#             out.append((before, after))
    
#     return out

# def generateAllSplits(facs):
#     return \
#         [[[x[1] for x in f]
#         for f in partition(lambda x: x[0], zip(pattern, facs))]
#         for pattern in product([True, False], repeat=len(facs))
#         if pattern]

# def generateSums(list_of_tuples_of_lists):
#     seen = []
#     out = []

#     for tuple_of_lists in list_of_tuples_of_lists:
#         # if tuple_of_lists in seen:
#         #     continue
#         # seen.append(tuple_of_lists)
#         sum1 = sum(tuple_of_lists[0])
#         sum2 = sum(tuple_of_lists[1])

#         out.append((sum1, sum2))
    
#     return out


# # numbers_set = list(range(1, N + 1))
# # cuts = (generateAllSplits(numbers_set))
# # sums_per_cut = generateSums(cuts)

# # count = 0

# # for sums in sums_per_cut:
# #     if sums[0] == sums[1]:
# #         count += 1

# # count /= 2

s = N * (N + 1)

if s % 4:
    count = 0

else:
    s /= 4
    buckets = [0 if _ else 1 for _ in range(1024)]
    for i in range(1, N):
        for j in range(int(s), i-1, -1):
            buckets[int(j)] += buckets[int(j - i)]
    
    count = buckets[int(s)]

with open('subset.out', 'w') as file:
    file.write(str(int(count)) + '\n')