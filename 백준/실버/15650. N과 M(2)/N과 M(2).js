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

  for (let i = x; i < n; ++i) {
    if (!vistied[i + 1]) {
      vistied[i + 1] = 1;
      arr.push(i + 1);
      dfs(i + 1);
      arr.pop();
      vistied[i + 1] = 0;
    }
  }
}
dfs(0);
