const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [n, m] = stdin[0].split(" ").map(Number);
const arr = stdin[1].split(" ").map(Number);
const arr2 = stdin.slice(2).map((str) => str.split(" ").map(Number));

function solution(n, m, arr, arr2) {
  const answer = [];
  const sum = new Array(n).fill(0);

  for (let i = 0; i < n; ++i) {
    if (i === 0) sum[i] = arr[i];
    else sum[i] = sum[i - 1] + arr[i];
  }

  arr2.forEach((item) => {
    const [start, end] = item;

    answer.push(sum[end - 1] - sum[start - 1] + arr[start - 1]);
  });

  answer.forEach((num) => console.log(num));
}

solution(n, m, arr, arr2);
