const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin.shift();

function solution() {
  const dp = new Array(N + 1).fill(5001);

  dp[3] = 1;
  dp[5] = 1;
  for (let i = 6; i <= N; ++i) {
    dp[i] = Math.min(dp[i - 3], dp[i - 5]) + 1;
  }

  console.log(dp[N] >= 5001 ? -1 : dp[N]);
}

solution();
