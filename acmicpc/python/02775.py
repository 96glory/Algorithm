arr = [[0 for col in range(15)] for row in range(15)]

for i in range(1, 15):
    arr[0][i] = i

for i in range(1, 15):
    temp_sum = 0
    for j in range(1, 15):
        temp_sum += arr[i - 1][j]
        arr[i][j] = temp_sum


cases = int(input())
for _ in range(cases):
    k = int(input())
    n = int(input())
    print(arr[k][n])