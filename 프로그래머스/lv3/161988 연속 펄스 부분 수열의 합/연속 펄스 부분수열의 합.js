function solution(sequence) {
  const dp = Array.from(Array(sequence.length), () => [-Infinity, -Infinity]);

  dp[0][0] = sequence[0];
  dp[0][1] = -sequence[0];

  let mx = Math.max(dp[0][0], dp[0][1]);

  for (let i = 1; i < sequence.length; ++i) {
    dp[i][0] = Math.max(sequence[i], sequence[i] + dp[i - 1][1]);
    dp[i][1] = Math.max(-sequence[i], -sequence[i] + dp[i - 1][0]);

    mx = Math.max(mx, dp[i][0], dp[i][1]);
  }

  return mx;
}
