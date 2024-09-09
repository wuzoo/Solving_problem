const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [A, K] = stdin[0].split(" ").map(Number);

function solution2() {
  const visited = new Array(1000001).fill(0);

  const dx = (cur) => [cur * 2, cur + 1];

  const q = [[A, 0]];
  visited[A] = 1;
  let index = 0;
  while (q.length > index) {
    const [node, cnt] = q[index++];

    if (node === K) {
      console.log(cnt);
      return;
    }

    for (const v of dx(node)) {
      if (v < 1 || v > K) continue;

      if (!visited[v]) {
        visited[v] = 1;
        q.push([v, cnt + 1]);
      }
    }
  }
}

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

solution2();

solution();
