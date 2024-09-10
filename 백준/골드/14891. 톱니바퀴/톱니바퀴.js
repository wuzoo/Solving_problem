const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

let arr = stdin.slice(0, 4);

let K = +stdin[4];

let index = 5;

while (K--) {
  const isRotate = new Array(4).fill(false);

  const [num, direction] = stdin[index].split(" ").map(Number);
  index++;

  let curNum = num - 1;
  let curLeftNum = num - 2;
  let curRightNum = num;

  isRotate[curNum] = true;

  while (curLeftNum >= 0 || curRightNum < 4) {
    if (curLeftNum >= 0 && isRotate[curLeftNum + 1]) {
      if (arr[curLeftNum][2] !== arr[curLeftNum + 1][6]) {
        isRotate[curLeftNum] = true;
      }
    }
    if (curRightNum < 4 && isRotate[curRightNum - 1]) {
      if (arr[curRightNum][6] !== arr[curRightNum - 1][2]) {
        isRotate[curRightNum] = true;
      }
    }

    curLeftNum = curLeftNum - 1;
    curRightNum = curRightNum + 1;
  }

  const startindexIsOdd = num % 2;

  isRotate.forEach((isrotated, idx) => {
    if (isrotated) {
      const d = startindexIsOdd === (idx + 1) % 2 ? direction : -direction;

      if (d === 1) {
        const current = arr[idx];

        arr[idx] = current.at(-1) + current.slice(0, -1);
      } else {
        arr[idx] = arr[idx].slice(1) + arr[idx][0];
      }
    }
  });
}

let sum = 0;
arr.forEach((str, idx) => {
  if (str[0] === "1") {
    sum += Math.pow(2, idx);
  }
});

console.log(sum);
