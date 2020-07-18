t = int(input())
n = 0
p = 0
sums = []
for i in range(1, 2*t + 1):
    if i % 2 != 0:
        n, p = [int(s) for s in input().split(" ")]
    else:
        players = [int(s) for s in input().split(" ")]
        players.sort()
        sums = players[:]
        for l in range(1, len(sums)):
            sums[l] = sums[l] + sums[l-1]
        sums.insert(0, 0)
        print(players, sums)
        minDiff = float('inf')
        for j in range(0, n-p+1):
            totalDiff = players[j+p-1] * p - (sums[j+p] - sums[j])
            if totalDiff < minDiff:
                minDiff = totalDiff
        print("Case #" + str(int(i/2)) + ": " + str(minDiff))

