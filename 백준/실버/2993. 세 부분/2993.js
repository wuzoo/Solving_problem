const fs = require("fs");
const input = fs.readFileSync("ex.txt").toString().trim().split("\n");

const str = input[0];

function solution(str) {
  let answer = "";

  const first = [];

  for (let i = 0; i < str.length - 2; ++i) {
    first.push(str[i]);

    const second = [];

    let thirdword = "";
    for (let j = i + 1; j < str.length - 1; ++j) {
      second.push(str[j]);

      const third = [];
      for (let k = j + 1; k < str.length; ++k) {
        third.push(str[k]);
      }
      thirdword = [...third].reverse().join("");

      const word =
        [...first].reverse().join("") +
        [...second].reverse().join("") +
        thirdword;

      if (answer === "" || answer > word) {
        answer = word;
      }
    }
  }

  console.log(answer);
}

solution(str);
