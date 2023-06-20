
nums = list(map(int, input().split()))
ans = 0
for i, num in enumerate(nums):
    ans += num << i
print(ans)
