var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [n, ...array] = input.map(Number);
let dp = new Array(n).fill(1);

for (let i = 0; i < n; ++i) {
  for (let j = 0; j < i; ++j) {
    if (array[i] > array[j]) {
      dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }
}

console.log(Math.max(...dp));
