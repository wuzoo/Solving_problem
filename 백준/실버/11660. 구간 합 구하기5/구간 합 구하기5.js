const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const graph = stdin.slice(1, N + 1).map((str) => str.split(" ").map(Number));
const arr = stdin.slice(N + 1).map((str) => str.split(" ").map(Number));

function solution() {
  const sum = Array.from(Array(N + 1), () => Array(N + 1).fill(0));

  for (let i = 1; i <= N; ++i) {
    for (let j = 1; j <= N; ++j) {
      sum[i][j] =
        sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + graph[i - 1][j - 1];
    }
  }

  const answer = [];

  arr.forEach((item) => {
    const [x1, y1, x2, y2] = item;

    answer.push(
      sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]
    );
  });

  answer.forEach((num) => console.log(num));
}

solution();
