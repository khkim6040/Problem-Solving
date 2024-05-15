import sys

input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
m = int(input())
compare = list(map(int, input().split()))

nums.sort()

for num in compare:
    low = 0
    high = n - 1
    flag = 0
    while low + 1 < high:
        mid = (low + high) // 2
        if num == nums[mid]:
            flag = 1
            break
        elif num > nums[mid]:
            low = mid
        else:
            high = mid

    if num == nums[low] or num == nums[high]:
        flag = 1

    if flag == 1:
        print(1)
    else:
        print(0)
