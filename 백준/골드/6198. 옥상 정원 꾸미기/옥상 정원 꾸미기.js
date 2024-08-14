const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const arr = stdin.slice(1).map(Number);

function solution(N, arr) {
  const answer = Array.from(Array(N), () => 0);
  const st = [];
  for (let i = N - 1; i >= 0; --i) {
    while (st.length && st[st.length - 1][0] < arr[i]) {
      st.pop();
    }
    if (st.length === 0) {
      answer[i] = N - 1 - i;
    } else {
      answer[i] = st[st.length - 1][1] - i - 1;
    }
    st.push([arr[i], i]);
  }

  console.log(answer.reduce((acc, cur) => acc + cur, 0));
}

solution(N, arr);
