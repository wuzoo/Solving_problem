const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const rc = stdin.pop();
const [r, c] = rc.split(" ").map(Number);
const graph = stdin.map((str) => str.split(" ").map(Number));

const dx = [0, 0, -1, 1];
const dy = [1, -1, 0, 0];

function solution() {
  const visited = Array.from(Array(5), () => Array(5).fill(0));

  function bfs(x, y) {
    const q = [[x, y, 0]];
    visited[x][y] = 1;

    while (q.length) {
      const [curX, curY, cnt] = q.shift();

      if (graph[curX][curY] === 1) {
        return cnt;
      }

      for (let i = 0; i < 4; ++i) {
        const nx = curX + dx[i];
        const ny = curY + dy[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny]) continue;
        if (graph[nx][ny] === -1) continue;

        visited[nx][ny] = 1;
        q.push([nx, ny, cnt + 1]);
      }
    }

    return -1;
  }

  console.log(bfs(r, c));
}

solution();
