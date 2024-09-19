const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

function solution() {
  const [A, B] = stdin[0].split(" ");
  const visited = new Array(A.length).fill(0);

  let max = 0;
  function DFS(k, str) {
    if (k === A.length) {
      if (+B > +str && max < +str && str[0] !== "0") {
        max = Math.max(max, +str);
      }
      return;
    }
    for (let i = 0; i < A.length; ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        DFS(k + 1, str + A[i]);
        visited[i] = 0;
      }
    }
  }

  DFS(0, "");

  console.log(max === 0 ? -1 : max);
}

solution();
