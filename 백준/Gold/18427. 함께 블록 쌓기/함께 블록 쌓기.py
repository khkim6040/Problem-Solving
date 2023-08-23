N, M, H = map(int, input().split())

blocks_list = [0 for _ in range(N)]
for i in range(N):
    nums = list(map(int, input().split()))
    blocks_list[i] = nums

# DP
MOD = 10007
dp = [0 for _ in range(H+1)]
dp[0] = 1
for blocks in blocks_list:
    increased_temp = [0 for _ in range(H+1)]
    for block in blocks:
        for i in range(H+1):
            if i+block > H:
                break
            increased_temp[i+block] = (increased_temp[i+block]+dp[i])%MOD
    for i in range(H+1):
        if increased_temp[i]:
            dp[i] = (dp[i]+increased_temp[i])%MOD

print(dp[H])