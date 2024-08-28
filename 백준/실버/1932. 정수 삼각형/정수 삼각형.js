const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const n = +stdin.shift();
const arr = stdin.map((str) => str.split(" ").map(Number));

function solution() {
  const dp = Array.from(Array(n), (_, i) => Array(i + 1).fill(0));

  dp[0][0] = arr[0][0];
  for (let i = 1; i < n; ++i) {
    for (let j = 0; j < dp[i].length; ++j) {
      if (j === 0) {
        dp[i][j] = dp[i - 1][j] + arr[i][j];
      } else {
        dp[i][j] = dp[i - 1][j - 1] + arr[i][j];

        if (j !== dp[i].length - 1) {
          dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + arr[i][j]);
        }
      }
    }
  }

  console.log(Math.max(...dp[n - 1]));
}

solution();
