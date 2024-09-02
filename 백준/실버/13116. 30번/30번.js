const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

let T = +stdin[0];

let index = 1;
while (T--) {
  const [A, B] = stdin[index].split(" ").map(Number);
  index++;

  let answer = 0;

  const arrA = [A];
  const arrB = [B];

  let nodeA = A;
  let nodeB = B;

  while (true) {
    const parent = Math.floor(nodeA / 2);

    if (parent <= 1) {
      arrA.push(1);
      break;
    }

    arrA.push(parent);
    nodeA = parent;
  }

  while (true) {
    const parent = Math.floor(nodeB / 2);

    if (parent <= 1) {
      arrB.push(1);
      break;
    }

    arrB.push(parent);
    nodeB = parent;
  }

  for (let i = 0; i < arrA.length; ++i) {
    if (arrB.includes(arrA[i])) {
      answer = arrA[i];
      break;
    }
  }

  console.log(answer * 10);
}
