def evaluateCase(case_num):
    A, B = list(map(int, input().split()))
    N = int(input())

    while N > 0:
        guess = (A+B+1)//2
        print("{}".format(guess))
        result = input()
        if result == "TOO_BIG":
            B = guess-1
        if result == "TOO_SMALL":
            A = guess
        if result == "CORRECT" or result == "WRONG_ANSWER":
            return
        N = N - 1


num_test_cases = int(input())
for case in range(num_test_cases):
    evaluateCase(case+1)
