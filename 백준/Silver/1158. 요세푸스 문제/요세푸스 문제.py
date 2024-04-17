from collections import deque

N, K = map(int, input().split())
start = deque()
res = []
for i in range(N):
    start.append(i + 1)
while len(start) != 0:
    for i in range(K):
        if i == K - 1:
            res.append(start.popleft())
        else:
            start.append(start.popleft())
print("<", end="")
print(*res, sep=', ', end='')
print(">")
# 시간초과코드