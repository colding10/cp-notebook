from bisect import *

n, m = map(int, input().split())

prices = list(map(int, input().split()))
prices.sort()

offers = list(map(int, input().split()))

for offer in offers:
	index = bisect_right(prices, offer)
	if index:
		print(prices.pop(index-1))
	else:
		print(-1)
