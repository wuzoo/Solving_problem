const fs = require("fs");
const stdin = fs.readFileSync("dev/stdin").toString().trim().split("\n");

const N = +stdin[0];
const arr = stdin.slice(1).map(Number);

function solution(N, arr) {
  const modeArr = Array.from({ length: 8001 }, () => [null, 0]);

  arr.sort((a, b) => a - b);

  const sum = arr.reduce((acc, cur) => acc + cur, 0);

  const aver = Math.round(sum / N);
  const mid = arr[Math.floor(arr.length / 2)];

  arr.forEach((num) => {
    modeArr[num + 4000][0] = num;
    modeArr[num + 4000][1]++;
  });

  modeArr.sort((a, b) => b[1] - a[1]);

  let mode;
  if (modeArr[0][1] === modeArr[1][1]) {
    mode = modeArr[1][0];
  } else {
    mode = modeArr[0][0];
  }
  const range = arr.at(-1) - arr.at(0);

  console.log(`${aver}\n${mid}\n${mode}\n${range}`);
}

solution(N, arr);
