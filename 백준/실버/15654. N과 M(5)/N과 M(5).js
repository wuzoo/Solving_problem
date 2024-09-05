const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const input = stdin[1].split(" ").map(Number);

function solution() {
  const arr = Array.from({ length: N + 1 }, () => 0);
  const visited = Array.from({ length: 10 }, () => 0);

  input.sort((a, b) => a - b);

  function DFS(k) {
    if (k === M) {
      console.log(arr.filter((num) => num !== 0).join(" "));
      return;
    }

    for (let i = 0; i < N; ++i) {
      if (!visited[i]) {
        arr[k] = input[i];
        visited[i] = 1;
        DFS(k + 1);
        visited[i] = 0;
      }
    }
  }

  DFS(0);
}

solution();
