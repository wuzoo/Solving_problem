const fs = require("fs");
const input = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = input.shift().split(" ").map(Number);

function solution() {
  let answer = "";

  const dict = ["A", "C", "G", "T"];
  const arr = Array.from(Array(M), () => Array(4).fill(0));

  input.forEach((str) => {
    str.split("").forEach((char, idx) => {
      let dictIdx = dict.indexOf(char);

      arr[idx][dictIdx]++;
    });
  });

  arr.forEach((arr) => {
    const max = Math.max(...arr);

    answer += dict[arr.indexOf(max)];
  });

  let cnt = 0;
  input.forEach((str) => {
    str.split("").forEach((char, idx) => {
      if (answer[idx] !== char) {
        cnt++;
      }
    });
  });

  console.log(answer);
  console.log(cnt);
}

solution();
