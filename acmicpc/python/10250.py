cases = int(input())

for _ in range(cases):
    h, w, n = map(int, input().split())
    cus_h = 0
    cus_w = 1
    for _ in range(n):
        cus_h += 1
        if cus_h > h:
            cus_h = 1
            cus_w += 1
    if cus_w < 10:
        print(cus_h, cus_w, sep="0")
    else:
        print(cus_h, cus_w, sep="")