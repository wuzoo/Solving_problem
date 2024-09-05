const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const T = +stdin[0];
const arr = stdin.slice(1).map((str) => str.split(" ").map(Number));

function solution(T, arr) {
  const answer = [];

  let idx = 0;

  while (T--) {
    const [x, y] = arr[idx];
    const distance = y - x;

    if (Number.isInteger(Math.sqrt(distance))) {
      answer.push(2 * Math.sqrt(distance) - 1);
    } else {
      const lower = Math.pow(Math.floor(Math.sqrt(distance)), 2) + 1;
      const upper = Math.pow(Math.floor(Math.sqrt(distance)) + 1, 2);
      const mid = (lower + upper) / 2;

      if (distance < mid) {
        answer.push(2 * Math.floor(Math.sqrt(distance)));
      } else {
        answer.push(2 * Math.floor(Math.sqrt(distance)) - 1 + 2);
      }
    }

    idx++;
  }

  answer.forEach((num) => console.log(num));
}

solution(T, arr);
