const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [str, T] = stdin;

const cnts = Array.from(Array(str.length + 1), () => Array(27).fill(0));

for (let i = 1; i <= str.length; ++i) {
  const alpha = str[i - 1].codePointAt() - 96;

  cnts[i][alpha]++;
  for (let j = 1; j <= 26; ++j) {
    cnts[i][j] += cnts[i - 1][j];
  }
}

const arr = stdin.slice(2);

let answer = "";
arr.forEach((elem) => {
  let [char, start, end] = elem.split(" ");

  start = +start + 1;
  end = +end + 1;

  answer += `${
    cnts[end][char.codePointAt() - 96] -
    cnts[start - 1][char.codePointAt() - 96]
  }\n`;
});

console.log(answer.trim());
