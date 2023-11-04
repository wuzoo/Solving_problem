var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().trim().split(" "); // 개행문자로 입력을 구분한다.

const n = input[0];

let count1 = 0;
let count2 = 0;

let f = new Array(n + 1).fill(0);

function fib1(n) {
  if (n === 1 || n === 2) {
    count1++;
    return 1;
  } else {
    return fib1(n - 1) + fib1(n - 2);
  }
}
function fib2(n) {
  f[1] = f[2] = 1;
  for (let i = 3; i <= n; ++i) {
    count2++;
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

fib1(n);
fib2(n);

console.log(count1, count2);
