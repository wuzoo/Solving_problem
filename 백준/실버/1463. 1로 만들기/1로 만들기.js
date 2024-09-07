const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const X = +stdin[0];

function solution() {
  const dp = new Array(1000001).fill(2000001);

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;

  for (let i = 4; i <= X; ++i) {
    dp[i] = dp[i - 1];
    if (i % 3 === 0) {
      dp[i] = Math.min(dp[i], dp[i / 3]);
    }
    if (i % 2 === 0) {
      dp[i] = Math.min(dp[i], dp[i / 2]);
    }
    dp[i]++;
  }

  console.log(dp[X]);
}

solution();
