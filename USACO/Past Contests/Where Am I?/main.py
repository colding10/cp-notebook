#Take in input using Python file i/o system
file_in = open('whereami.in')
data = file_in.read().strip().split('\n')
n = int(data[0])
mailboxes = data[1]

# Set the answer initially to n, as we know n is always a possible answer
ans = n

# We can iterate through lengths of sequences to find the smallest length
for l in range(1, n + 1):
	# Store the substrings in a set
	sequences = {mailboxes[i : i + l] for i in range(n - l + 1)}
	# Check if all substrings are unique
	if len(sequences) == (n - l + 1):
		ans = l
		# We can exit the loop as this will be the smallest working length
		break

print(ans, file = open('whereami.out', 'w'))