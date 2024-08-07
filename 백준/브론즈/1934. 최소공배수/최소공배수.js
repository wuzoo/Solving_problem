const fs = require("fs");
const stdin = fs.readFileSync("dev/stdin").toString().trim().split("\n");

const T = +stdin[0];
const arr = stdin.slice(1).map((str) => str.split(" ").map(Number));

function gcd(a, b) {
  if (b === 0) return a;
  return gcd(b, a % b);
}
function solution() {
  const answer = [];

  arr.forEach((item) => {
    const [a, b] = item;

    const d = gcd(a, b);

    answer.push((a * b) / d);
  });

  answer.forEach((num) => console.log(num));
}

solution(T, arr);
