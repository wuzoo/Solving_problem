const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const arr = stdin[1].split(" ").map(Number);

function solution(N, arr) {
  const answer = Array.from({ length: N }, () => 0);
  const st = [];

  for (let i = N - 1; i >= 0; --i) {
    while (st.length && arr[i] >= st.at(-1)) {
      st.pop();
    }
    if (st.length === 0) {
      answer[i] = -1;
    } else {
      answer[i] = st.at(-1);
    }
    st.push(arr[i]);
  }

  console.log(answer.join(" "));
}

solution(N, arr);
