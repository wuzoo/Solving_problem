function solution(m, n, puddles) {
  const INF = 1000000007;

  const map = Array.from(Array(m + 1), () => Array(n + 1).fill(0));
  const dp = Array.from(Array(m + 1), () => Array(n + 1).fill(0));

  puddles.forEach((arr) => {
    const [x, y] = arr;
    map[x][y] = 1;
  });

  dp[1][1] = 1;
  for (let i = 1; i <= n; ++i) {
    for (let j = 1; j <= m; ++j) {
      if (map[j][i] === 1) continue;
      if (j === 1 && i === 1) continue;

      dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % INF;
    }
  }

  return dp[m][n];
}
