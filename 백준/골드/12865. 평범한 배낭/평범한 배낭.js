const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, K] = stdin.shift().split(" ").map(Number);

const input = stdin.map((str) => str.split(" ").map(Number));

function solution() {
  const dp = Array.from(Array(N + 1), () => Array(K + 1).fill(0));

  input.unshift([0, 0]);

  for (let i = 1; i <= N; ++i) {
    for (let j = 0; j <= K; ++j) {
      if (j - input[i][0] >= 0) {
        dp[i][j] = Math.max(
          dp[i - 1][j],
          dp[i - 1][j - input[i][0]] + input[i][1]
        );
      }
      dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
    }
  }

  console.log(dp[N][K]);
}

solution();
