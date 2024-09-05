const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = stdin[0];

function solution(N) {
  const dict = N.split("").map(Number);

  if (!dict.includes(0)) {
    console.log(-1);
    return;
  }

  const sum = dict.reduce((acc, cur) => acc + cur, 0);

  dict.sort((a, b) => b - a);

  if (sum % 3 === 0) {
    console.log(dict.join(""));
  } else {
    console.log(-1);
  }
}

solution(N);
