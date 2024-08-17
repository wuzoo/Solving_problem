const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [A, B] = stdin[0].split(" ").map(Number);

console.log(A - B);
