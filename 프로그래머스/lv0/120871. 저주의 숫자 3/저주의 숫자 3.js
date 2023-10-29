function solution(n) {
  let dp = new Array(101).fill(0);
  dp[1] = 1;
  dp[2] = 2;
  for (let i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + 1;
    if (dp[i] % 3 === 0 || dp[i].toString().includes("3")) {
      while (dp[i] % 3 === 0 || dp[i].toString().includes("3")) {
        dp[i]++;
      }
    }
  }

  return dp[n];
}
