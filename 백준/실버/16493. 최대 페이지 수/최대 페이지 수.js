const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin.shift().split(" ").map(Number);

function solution() {
  const dp = Array.from(Array(M + 1), () => Array(201).fill(0));

  const input = stdin.map((str) => str.split(" ").map(Number));
  input.unshift([0, 0]);

  for (let i = 1; i <= M; ++i) {
    // 챕터
    for (let j = 0; j <= N; ++j) {
      // 일 수

      if (j - input[i][0] >= 0) {
        dp[i][j] = Math.max(
          dp[i - 1][j],
          dp[i - 1][j - input[i][0]] + input[i][1]
        );
      }
      dp[i][j] = Math.max(dp[i - 1][j], dp[i][j]);
    }
  }

  console.log(dp[M][N]);
}

solution();
