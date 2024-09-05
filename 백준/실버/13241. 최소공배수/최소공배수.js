const fs = require("fs");
const input = fs
  .readFileSync("dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

const [A, B] = input;

function gcd(a, b) {
  if (b === 0) return a;

  return gcd(b, a % b);
}

console.log((A * B) / gcd(A, B));
