const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];

function solution() {
  let start = BigInt(N);
  let sum = BigInt(1);

  while (start > 1) {
    sum *= start;
    start -= BigInt(1);
  }

  const str = (sum + "").split("");

  let cnt = 0;
  for (let i = str.length - 1; i >= 0; --i) {
    if (str[i] === "0") {
      cnt++;
    } else {
      break;
    }
  }

  console.log(cnt);
}

solution();
