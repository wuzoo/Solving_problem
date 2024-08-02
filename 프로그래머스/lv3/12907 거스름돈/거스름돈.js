function solution(n, money) {
  const dp = Array.from(Array(n + 1), () => 0);

  dp[0] = 1;
  money.forEach((num) => {
    // 1 2 5
    for (let i = num; i <= n; ++i) {
      dp[i] += dp[i - num] % 1000000007;
    }
  });

  return dp[n];
}
