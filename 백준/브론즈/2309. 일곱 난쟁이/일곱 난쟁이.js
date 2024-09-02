const fs = require("fs");
const input = fs.readFileSync("ex.txt").toString().trim().split("\n");

const arr = input.map(Number);

function solution() {
  const answer = [];
  const idxs = [];

  const sum = arr.reduce((acc, cur) => acc + cur, 0);

  for (let i = 0; i < arr.length; ++i) {
    const first = arr[i];
    for (let j = 0; j < arr.length; ++j) {
      if (i === j) continue;

      const second = arr[j];

      if (sum - (first + second) === 100) {
        idxs.push(i, j);
        break;
      }
    }
  }
  const [i, j] = idxs;

  arr.forEach((num) => {
    if (num !== arr[i] && num !== arr[j]) {
      answer.push(num);
    }
  });

  answer.sort((a, b) => a - b).forEach((num) => console.log(num));
}

solution();
