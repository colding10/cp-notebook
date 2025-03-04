import sys

sys.setrecursionlimit(10000)

def checkCitiesConnected(city_a: int, city_b: int, illegal: list):
    if city_a in illegal:
        return False
    if city_a == city_b:
        return True
    if city_a in visited:
        return False
    
    visited.add(city_a)
    
    for neighbor in graph[city_a]:
        can_reach_b = checkCitiesConnected(neighbor, city_b, illegal)
        if can_reach_b == True:
            return True
    
    return False
    

CITIES, ROADS, QUERIES = map(int, input().split())

graph = {}

for _ in range(ROADS):
    city_a, city_b = map(int, input().split())
    
    if city_a not in graph:
        graph[city_a] = []
    if city_b not in graph:
        graph[city_b] = []
    
    graph[city_a].append(city_b)
    graph[city_b].append(city_a)

for _ in range(QUERIES):
    visited = set()
    
    city_a, city_b, forbidden_city = map(int, input().split())
    if checkCitiesConnected(city_a, city_b, [forbidden_city]):
        print('YES')
    else:
        print('NO')
    