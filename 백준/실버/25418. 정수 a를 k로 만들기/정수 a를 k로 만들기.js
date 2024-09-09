const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [A, K] = stdin[0].split(" ").map(Number);

function solution() {
  const dp = new Array(K + 1).fill(1000001);

  function topdown(num, k) {
    if (num === A) {
      console.log(k);
      process.exit();
    }

    if (num < A) {
      return k;
    }

    if (num % 2 === 0) {
      dp[num] = topdown(num / 2, k + 1);
    }

    dp[num] = Math.min(dp[num], topdown(num - 1, k + 1));

    return dp[num];
  }

  topdown(K, 0);

  console.log(dp[K]);
}

solution();
