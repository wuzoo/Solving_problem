const fs = require("fs");
const [A, B, C] = fs
  .readFileSync("ex.txt")
  .toString()
  .trim()
  .split("\n")
  .at(0)
  .split(" ")
  .map(BigInt);

function pow(base, expo) {
  if (expo === BigInt(1)) {
    return base % C;
  }

  const k = pow(base, expo / BigInt(2));

  if (expo % BigInt(2) === BigInt(0)) {
    return (k * k) % C;
  }

  return (((k * k) % C) * A) % C;
}

console.log(pow(A, B).toString());
