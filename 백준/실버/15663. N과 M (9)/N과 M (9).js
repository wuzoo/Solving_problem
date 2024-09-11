const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const input = stdin[1].split(" ").map(Number);

function solution() {
  input.sort((a, b) => a - b);
  const answer = [];

  const visited = new Array(N).fill(0);
  const arr = new Array(M).fill(0);

  function DFS(k) {
    if (k === M) {
      answer.push(arr.join(" "));
      return;
    }

    let last = 0;
    for (let i = 0; i < N; ++i) {
      if (!visited[i] && last !== input[i]) {
        arr[k] = input[i];
        visited[i] = 1;
        last = input[i];
        DFS(k + 1, i);
        visited[i] = 0;
      }
    }
  }

  DFS(0, 0);

  answer.forEach((str) => console.log(str));
}

solution();
