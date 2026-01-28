from itertools import product

lines = []
with open("input.txt", "r") as file:
    for line in file.readlines():
        ttl, rest = line.strip().split(": ")
        ttl = int(ttl)
        rest = list(map(int, rest.split()))
        lines.append((ttl, rest))

# PART 1
# def evaluate_expressions(numbers):
#     if len(numbers) == 1:
#         return {numbers[0]} 
#     operators = list(product("+*", repeat=len(numbers) - 1))
#     results = set()

#     for ops in operators:
#         result = numbers[0]
#         for i, op in enumerate(ops):
#             if op == "+":
#                 result += numbers[i + 1]
#             elif op == "*":
#                 result *= numbers[i + 1]
#         results.add(result)

#     return results


# out = 0
# for ttl, rest in lines:
#     if ttl in evaluate_expressions(rest):
#         out += ttl

# print(out)


# PART 2


def recurse(val, nums, doing_concat=True):
    *head, current = nums
    if not head:
        return current == val
    q, r = divmod(val, current)
    if r == 0 and recurse(q, head, doing_concat):
        return True
    if doing_concat:
        b_digits = len(str(current))
        if val % (10 ** b_digits) == current:
            cut_val = val // (10 ** b_digits)
            if recurse(cut_val, head, doing_concat):
                return True
    return recurse(val - current, head, doing_concat)



out = 0
for val, nums in lines:
    if recurse(val, nums, False):
        out += val
    elif recurse(val, nums):
        out += val
print(out)