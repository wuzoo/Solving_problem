const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const arr = stdin.slice(1).map((str) => str.split(" "));

function solution(T, arr) {
  arr.sort((a, b) => +a[0] - +b[0]);

  arr.forEach((item) => {
    console.log(item.join(" "));
  });
}

solution(N, arr);
