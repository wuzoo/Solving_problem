const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

let T = +stdin.shift();

stdin.map(Number).forEach((num) => {
  const dp = new Array(12).fill(0);

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (let i = 4; i <= num; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  console.log(dp[num]);
});
