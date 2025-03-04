from collections import defaultdict


def simulate_stones_optimized(input_file, blinks):
    with open(input_file, "r") as f:
        stones = list(map(int, f.readline().strip().split()))

    freq = defaultdict(int)
    for stone in stones:
        freq[stone] += 1

    for _ in range(blinks):
        new_freq = defaultdict(int)
        for stone, count in freq.items():
            if stone == 0:
                new_freq[1] += count
            elif len(str(stone)) % 2 == 0:
                num_str = str(stone)
                mid = len(num_str) // 2
                left, right = int(num_str[:mid]), int(num_str[mid:])
                new_freq[left] += count
                new_freq[right] += count
            else:
                new_freq[stone * 2024] += count
        freq = new_freq
    return sum(freq.values())


input_file = "input.txt"
blinks = 75
result = simulate_stones_optimized(input_file, blinks)
print(result)
