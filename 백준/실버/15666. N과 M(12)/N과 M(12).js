const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const input = stdin[1].split(" ").map(Number);

function solution() {
  const arr = Array.from({ length: N + 1 }, () => 0);

  input.sort((a, b) => a - b);

  function DFS(k, len) {
    if (len === M) {
      console.log(arr.filter((num) => num !== 0).join(" "));
      return;
    }

    let current = 0;

    for (let i = k; i < N; ++i) {
      if (input[i] !== current) {
        arr[len] = input[i];
        current = arr[len];
        DFS(i, len + 1);
      }
    }
  }

  DFS(0, 0);
}

solution();
