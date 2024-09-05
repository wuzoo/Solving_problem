const fs = require("fs");
let NM = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = NM[0].split(" ").map(Number);

function solution() {
  const visited = Array.from(Array(100001), () => 0);

  const q = [[N, 0]];
  visited[N] = 1;
  while (q.length) {
    const [cur, cnt] = q.shift();

    if (cur === M) {
      return cnt;
    }

    if (cur * 2 <= 100000) {
      if (!visited[cur * 2]) {
        visited[cur * 2] = 1;
        q.push([cur * 2, cnt + 1]);
      }
    }

    if (cur + 1 <= 100000) {
      if (!visited[cur + 1]) {
        visited[cur + 1] = 1;
        q.push([cur + 1, cnt + 1]);
      }
    }

    if (cur - 1 >= 0) {
      if (!visited[cur - 1]) {
        visited[cur - 1] = 1;
        q.push([cur - 1, cnt + 1]);
      }
    }
  }
}

console.log(solution());
