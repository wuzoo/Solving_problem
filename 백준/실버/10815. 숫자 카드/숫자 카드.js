const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const arr1 = stdin[1].split(" ").map(Number);
const M = +stdin[2];
const arr2 = stdin[3].split(" ").map(Number);

function solution(N, arr1, M, arr2) {
  arr1.sort((a, b) => a - b);

  function search(num) {
    let st = 0;
    let en = N - 1;
    while (st <= en) {
      const mid = Math.floor((st + en) / 2);

      if (arr1[mid] < num) {
        st = mid + 1;
      } else if (arr1[mid] > num) {
        en = mid - 1;
      } else {
        return 1;
      }
    }

    return 0;
  }
  const answer = [];

  arr2.forEach((num) => answer.push(search(num)));

  console.log(answer.join(" "));
}

solution(N, arr1, M, arr2);
