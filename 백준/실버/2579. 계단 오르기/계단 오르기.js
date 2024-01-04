var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().trim().split("\n"); // 개행문자로 입력을 구분한다.

const [n, ...score] = input.map(Number); // score [10, 20, 15, 25, 10, 20]

score.unshift(0);

let dp = new Array(n + 1).fill(0);

dp[0] = 0;
dp[1] = score[1];
dp[2] = Math.max(score[1] + score[2], score[2]);
dp[3] = Math.max(dp[1], score[2]) + score[3];

for (let i = 4; i <= n; ++i) {
  dp[i] = Math.max(score[i - 1] + dp[i - 3], dp[i - 2]) + score[i];
}

console.log(dp[n]);
