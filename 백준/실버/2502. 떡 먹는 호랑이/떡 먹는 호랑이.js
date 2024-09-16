const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [D, K] = stdin[0].split(" ").map(Number);

function solution() {
  const dp = Array.from(Array(D + 1), () => Array(3).fill(0));

  dp[1][1] = 1;
  dp[1][2] = 0;
  dp[2][1] = 0;
  dp[2][2] = 1;

  for (let i = 3; i <= D; ++i) {
    dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    dp[i][2] = dp[i - 1][2] + dp[i - 2][2];
  }

  let answer = [];
  for (let i = 1; i <= 100000; ++i) {
    const spare = K - dp[D][1] * i;

    if (spare % dp[D][2] === 0) {
      answer.push(i, spare / dp[D][2]);
      return answer.join("\n");
    }
  }
}

console.log(solution());
