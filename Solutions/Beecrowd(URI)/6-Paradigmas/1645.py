def Solve(nums, k):
    dp = [1] * len(nums)
    for _ in range(k - 1):
        for j in range(len(dp) - 1, -1, -1):
            dp[j] = 0
            for i in range(j):
                if nums[i] < nums[j]:
                    dp[j] += dp[i]
    return sum(dp)

while True:
    N, K = map(int, (input().split()))
    if not N and not K:
        break
    Vet = list()
    A = input().split()
    for i in A:
        Vet.append(int(i))
    print(Solve(Vet, K))