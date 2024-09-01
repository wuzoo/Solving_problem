const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const daegeun = stdin.slice(1, N + 1);
const yungsik = stdin.slice(N + 1);

function solution() {
  let answer = 0;
  const map = new Map();

  daegeun.forEach((str, idx) => {
    map.set(str, idx);
  });

  for (let i = 0; i < N; ++i) {
    for (let j = i + 1; j < N; ++j) {
      if (map.get(yungsik[j]) < map.get(yungsik[i])) {
        answer++;
        break;
      }
    }
  }

  console.log(answer);
}

solution();
