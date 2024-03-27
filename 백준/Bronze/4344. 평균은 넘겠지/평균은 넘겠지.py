C = int(input())
for i in range(C):
    numlist = list(map(int,input().split()))
    N = numlist[0]
    avg = sum(numlist[1:]) / N
    count = 0
    for num in numlist[1:]:
        if num > avg:
            count += 1
    print(f'{count/N*100:.3f}%')
    