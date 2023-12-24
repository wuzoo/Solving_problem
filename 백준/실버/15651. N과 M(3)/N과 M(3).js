var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().trim().split(" "); // 개행문자로 입력을 구분한다.
const [n, m] = input.map(Number);

let arr = [];

function dfs(x) {
  if (arr.length === m) {
    console.log(...arr);
    return;
  }

  for (let i = 1; i <= n; ++i) {
    arr.push(i);
    dfs(x + i);
    arr.pop();
  }
}
dfs(0);
