const fs = require("fs");
const stdin = fs.readFileSync("dev/stdin").toString().trim().split("\n");

const arr = stdin.map(Number);

const n = Array.from({ length: 300000 }, (_, i) => i + 1);

for (let i = 2; i < n.length; ++i) {
  if (n[i] === 0) continue;

  for (let j = i + i; j < n.length; j += i) {
    n[j] = 0;
  }
}

function isPrime(num) {
  if (num === 1) return false;

  return n[num] !== 0;
}

function solution(arr) {
  const answer = [];

  arr.forEach((item) => {
    let count = 0;
    for (let i = item + 1; i <= 2 * item; ++i) {
      if (isPrime(i)) count++;
    }
    answer.push(count);
  });

  answer.pop();

  answer.forEach((num) => console.log(num));
}

solution(arr);
