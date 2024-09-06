const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin.shift();

const pos = stdin.map((str) => str.split(" ").map(Number));

function solution() {
  const xarr = pos.map((item) => item[0]);
  const yarr = pos.map((item) => item[1]);

  xarr.sort((a, b) => a - b);
  yarr.sort((a, b) => a - b);

  let sumX = 0;
  let sumY = 0;

  xarr.forEach(
    (num) => (sumX += Math.abs(num - xarr[Math.floor(xarr.length / 2)]))
  );
  yarr.forEach(
    (num) => (sumY += Math.abs(num - yarr[Math.floor(yarr.length / 2)]))
  );

  console.log(sumX + sumY);
}

solution();
