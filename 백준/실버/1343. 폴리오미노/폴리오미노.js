const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const board = stdin[0];

function getConverted(str) {
  if (str.length % 2 !== 0) {
    return -1;
  }

  if (str.length % 4 === 0) {
    return str.replaceAll("X", "A");
  } else {
    return str.slice(0, str.length - 2).replaceAll("X", "A") + "BB";
  }
}

function solution() {
  let answer = "";
  let temp = "";

  for (let i = 0; i < board.length; ++i) {
    if (board[i] !== ".") {
      temp += board[i];

      if (i === board.length - 1) {
        const converted = getConverted(temp);

        if (converted === -1) {
          answer = -1;
          break;
        }
        answer += converted;
      }

      continue;
    } else if (board[i] === "." || i === board.length - 1) {
      const converted = getConverted(temp);

      if (converted === -1) {
        answer = -1;
        break;
      }
      answer += converted;

      answer += ".";
      temp = "";
    }
  }

  return answer;
}

console.log(solution());
