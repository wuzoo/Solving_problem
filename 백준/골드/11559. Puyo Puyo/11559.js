const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const dx = [0, 0, -1, 1];
const dy = [1, -1, 0, 0];

const input = stdin.map((str) => str.split(""));

function solution() {
  function BFS() {
    let success = false;
    const visited = Array.from(Array(13), () => Array(7).fill(0));
    for (let i = 0; i < 12; ++i) {
      for (let j = 0; j < 6; ++j) {
        const sign = input[i][j];

        if (sign === ".") continue;

        const result = [];
        const q = [[i, j]];
        visited[i][j] = 1;

        let index = 0;
        while (q.length > index) {
          const [x, y] = q[index++];

          result.push([x, y]);

          for (let i = 0; i < 4; ++i) {
            const nx = x + dx[i];
            const ny = y + dy[i];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            if (visited[nx][ny]) continue;
            if (input[nx][ny] !== sign) continue;

            visited[nx][ny] = 1;
            q.push([nx, ny]);
          }
        }

        if (result.length >= 4) {
          success = true;
          result.forEach(([x, y]) => (input[x][y] = "."));
        }
      }
    }
    return success;
  }

  function relocate() {
    for (let i = 0; i < 6; ++i) {
      let newArr = [];
      for (let j = 0; j < 12; ++j) {
        const sign = input[j][i];

        newArr.push(sign);
      }

      newArr = newArr.filter((char) => char != ".");

      while (newArr.length < 12) {
        newArr.unshift(".");
      }

      for (let j = 0; j < 12; ++j) {
        input[j][i] = newArr[j];
      }
    }
  }

  let cnt = 0;
  while (true) {
    if (BFS()) {
      cnt++;
      relocate();
    } else {
      break;
    }
  }

  console.log(cnt);
}

solution();
