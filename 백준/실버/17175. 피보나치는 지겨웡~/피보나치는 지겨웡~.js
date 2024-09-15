const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];

function solution() {
  const dp = new Array(N + 1).fill(0);

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 3;

  for (let i = 3; i <= N; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
  }

  console.log(dp[N]);
}

solution();
