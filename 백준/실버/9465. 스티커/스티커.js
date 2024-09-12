const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

let T = +stdin.shift();

let index = 0;
while (T--) {
  const N = ++stdin[index];
  index++;

  const arr = stdin
    .slice(index, index + 2)
    .map((str) => str.split(" ").map(Number));
  index += 2;

  const dp = Array.from(Array(N + 1), () => Array(3).fill(0));

  dp[1][1] = arr[0][0];
  dp[1][2] = arr[1][0];
  for (let i = 2; i <= N; ++i) {
    dp[i][1] =
      Math.max(dp[i - 2][1], dp[i - 2][2], dp[i - 1][2]) + arr[0][i - 1];
    dp[i][2] =
      Math.max(dp[i - 2][1], dp[i - 2][2], dp[i - 1][1]) + arr[1][i - 1];
  }

  console.log(Math.max(dp[N - 1][1], dp[N - 1][2]));
}
