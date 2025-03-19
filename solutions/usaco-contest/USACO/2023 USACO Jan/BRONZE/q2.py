class Cow:
    starting: int
    ending: int
    request: int

    def __init__(self, starting, ending, request):
        self.starting = int(starting)
        self.ending = int(ending)
        self.request = int(request)


class AC:
    starting: int
    ending: int
    amount: int
    cost: int

    def __init__(self, starting, ending, amount, cost):
        self.starting = int(starting)
        self.ending = int(ending)
        self.amount = int(amount)
        self.cost = int(cost)


def brute_force(n: int, m: int, cows, acs):
    cows_need = [0] * 100
    best_cost = int(sum([c.cost for c in acs]))

    for c in cows:
        for i in range(c.starting, c.ending + 1):
            cows_need[i] = max(cows_need[i], c.request)

    for i in range(1 << m):
        case = bin(i)[2:].rjust(m, "0")
        cost = 0
        cn = list(cows_need)

        for x in range(m):
            if case[x] == "1":
                ac = acs[x]

                temp_need = cn[ac.starting : ac.ending + 1]
                diff = [max(0, i - ac.amount) for i in temp_need]
                cost += ac.cost
                cn[ac.starting : ac.ending + 1] = diff

        if any(cn):
            continue

        best_cost = min(cost, best_cost)

    return best_cost


if __name__ == "__main__":
    n, m = map(int, input().split())
    cows = [Cow(*map(int, input().split())) for _ in range(n)]
    acs = [AC(*map(int, input().split())) for _ in range(m)]
    
    print(brute_force(n, m, cows, acs))
