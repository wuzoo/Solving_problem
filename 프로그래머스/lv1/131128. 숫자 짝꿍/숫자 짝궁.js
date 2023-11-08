function solution(X, Y) {
  let xarr = new Array(10).fill(0);
  let yarr = new Array(10).fill(0);
  let samenum = [];

  X.split("").forEach((item) => xarr[+item]++);
  Y.split("").forEach((item) => yarr[+item]++);

  for (let i = 0; i <= 9; ++i) {
    if (xarr[i] && yarr[i]) {
      let min = Math.min(xarr[i], yarr[i]);
      for (let j = 0; j < min; ++j) samenum.push(i);
    }
  }
  if (samenum.length === 0) return "-1";
  if (samenum.filter((v) => v !== 0).length === 0) return "0";
  return samenum.sort((a, b) => b - a).join("");
}
