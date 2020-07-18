def getTestCaseInput():
    rows, cols = list(map(int, input().split()))
    grid = [[0]*cols]*rows
    for i in range(rows):
        row = input()
        for j in range(len(row)):
            grid[i][j] = row[j]

    return grid


def evaluateCase(case_num):
    grid = getTestCaseInput()



num_test_cases = int(input())
for case in range(num_test_cases):
    evaluateCase(case+1)
