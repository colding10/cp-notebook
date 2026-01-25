import heapq

def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def main():
    N, M, K = read_ints()
    weights = [list(map(int, input().split())) for _ in range(N)]
    weights.sort(reverse=True)
    queue = []
    max_cows = 0
    tower_size = 0
    for i in range(N):
        while queue and weights[i] - K > queue[0][1]:
            heapq.heappop(queue)
        if queue and weights[i] >= queue[0][1] - K:
            tower_size += 1
            heapq.heappush(queue, (weights[i], queue[0][1] - K))
        else:
            if tower_size > M:
                tower_size -= 1
            max_cows += tower_size
            tower_size = 1
    if tower_size > M:
        tower_size -= 1
    max_cows += tower_size
    print(max_cows)

if __name__ == "__main__":
    main()