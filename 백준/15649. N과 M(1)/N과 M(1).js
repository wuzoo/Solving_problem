var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().trim().split(" "); // 개행문자로 입력을 구분한다.
const [n, m] = input.map(Number);

let vistied = new Array(n).fill(0);

let arr = [];

function dfs(x) {
  if (arr.length === m) {
    console.log(...arr);
    return;
  }

  for (let i = 1; i <= n; ++i) {
    if (!vistied[i]) {
      arr.push(i);
      vistied[i] = 1;
      dfs(x + i);
      vistied[i] = 0;
      arr.pop();
    }
  }
}
dfs(0);
