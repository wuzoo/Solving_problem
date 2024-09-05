const fs = require("fs");
const stdin = fs.readFileSync("dev/stdin").toString().trim().split("\n");

const N = +stdin[0];
const arr = stdin.slice(1).map((str) => str.split(" ").map(Number));

function solution(N, arr) {
  const answer = [];
  if (N === 2) {
    answer.push(1, 1);
  } else {
    const first = (arr[0][2] - arr[1][2] + arr[0][1]) / 2;
    answer.push(first);

    for (let i = 1; i < N; ++i) {
      answer.push(arr[0][i] - answer[0]);
    }
  }
  console.log(answer.join(" "));
}

solution(N, arr);
