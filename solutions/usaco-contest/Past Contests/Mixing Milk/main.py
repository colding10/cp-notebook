import sys
import itertools

sys.stdin = open('mixmilk.in')
sys.stdout = open('mixmilk.out', 'w')

class Bucket:
    def __init__(self, number: int, capacity: int, volume: int):
        self.capacity = capacity
        self.volume = volume
        self.number = number
    
    def pourInto(self, bucket):
        if bucket.volume >= bucket.capacity or self.volume == 0: # the bucket to pour into is full or this one empty
            return
        
        bucket.volume += self.volume
        self.volume = 0

        if bucket.volume > bucket.capacity:
            self.volume += bucket.volume - bucket.capacity
            bucket.volume = bucket.capacity
    
    def __repr__(self):
        return f'<__main__.Bucket #{self.number}>'

buckets = []

for N in range(3):
    bucket = Bucket(N, *map(int, sys.stdin.readline().strip().split()))
    buckets.append(bucket)

counter = 0
for i in itertools.cycle(range(3)):
    if counter >= 100:
        break

    pouring_bucket = buckets[i]
    recieving_bucket = buckets[(i + 1) % 3]

    pouring_bucket.pourInto(recieving_bucket)

    counter += 1

for bucket in buckets:
    print(bucket.volume)
