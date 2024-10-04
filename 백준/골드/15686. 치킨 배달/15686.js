const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [n, m] = stdin.shift().split(" ").map(Number);
const input = stdin.map((str) => str.split(" ").map(Number));

function solution() {
  const homes = [];
  const chickens = [];

  const picked = [];
  const visited = new Array(14).fill(0);

  let answer = Infinity;

  input.forEach((item, row) => {
    item.forEach((rowItem, col) => {
      if (rowItem === 1) {
        homes.push([row, col]);
      } else if (rowItem === 2) {
        chickens.push([row, col]);
      }
    });
  });

  function caculate() {
    let d = 0;
    homes.forEach((item) => {
      const [row, col] = item;

      let sum = Infinity;
      picked.forEach((item2) => {
        const [row2, col2] = item2;

        const distance = Math.abs(row - row2) + Math.abs(col - col2);

        sum = Math.min(sum, distance);
      });

      d += sum;
    });

    return d;
  }

  function permutation(idx, k) {
    if (k === m) {
      answer = Math.min(caculate(), answer);
      return;
    }

    for (let i = idx; i < chickens.length; ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        picked.push([chickens[i][0], chickens[i][1]]);
        permutation(i, k + 1);
        picked.pop();
        visited[i] = 0;
      }
    }
  }

  permutation(0, 0);

  console.log(answer);
}

solution();
