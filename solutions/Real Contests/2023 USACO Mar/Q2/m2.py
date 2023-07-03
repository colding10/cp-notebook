# read input values
C, N = map(int, input().split())

# read teams as a list of strings
teams = []
for i in range(N):
    teams.append(input().strip())

# function to calculate the difference between two teams
def team_difference(team1, team2):
    diff = 0
    for i in range(C):
        if team1[i] != team2[i]:
            diff += 1
    return diff

# calculate maximum difference for each team
for i in range(N):
    max_diff = 0
    for j in range(N):
        if i != j:
            diff = team_difference(teams[i], teams[j])
            max_diff = max(max_diff, diff)
    print(max_diff)
