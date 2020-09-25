L = list(input().split())

for i in range(len(L)):
    L[i] = int(L[i])

sortL = sorted(L)
print(sortL[1])