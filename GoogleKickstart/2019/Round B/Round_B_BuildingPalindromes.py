def create_count_array(charset, word):
    counts_array = [[0 for i in range(len(word)+1)] for j in charset]
    for char in charset:
        c = ord(char) - ord('A')
        for i in range(1, len(word)+1):
            if word[i-1] == char:
                counts_array[c][i] = 1
            counts_array[c][i] += counts_array[c][i-1]
    return counts_array


def is_palindrome(L, R, char_array):
    odd_chars = 0
    for i in range(len(char_array)):
        if (char_array[i][L-1] - char_array [i][R]) % 2 == 1:
            odd_chars += 1
        if odd_chars > 1:
            return 0
    return 1


num_test_cases = int(input())
CHARSET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for case in range(num_test_cases):
    N, Q = list(map(int, list(input().split())))
    sequence = input()
    count_array = create_count_array(CHARSET, sequence)
    count = 0
    for q in range(Q):
        L, R = list(map(int, list(input().split())))
        count += is_palindrome(L, R, count_array)
    print("Case #{}: {}".format(case+1, count))
