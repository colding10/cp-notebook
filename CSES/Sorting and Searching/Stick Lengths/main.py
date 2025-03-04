N = int(input())
numbers = sorted(list(map(int, input().split())))

target_length = numbers[len(numbers) // 2]
   
total = sum(abs(length - target_length) for length in numbers)

    
print(int(total))