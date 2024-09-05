function solution(dartResult) {
  var answer = 0;

  let cur = [];
  let starArray = new Array(3).fill(0);
  let achaArray = new Array(3).fill(0);

  let curIdx = -1;
  dartResult.split("").forEach((item) => {
    if (item === "0" && cur[cur.length - 1] === 1) {
      cur.pop();
      cur.push(10);
      curIdx++;
    } else if (/\d/.test(item)) {
      cur.push(+item);
      curIdx++;
    } else if (item === "S") {
      cur[cur.length - 1] = Math.pow(cur[cur.length - 1], 1);
    } else if (item === "D") {
      cur[cur.length - 1] = Math.pow(cur[cur.length - 1], 2);
    } else if (item === "T") {
      cur[cur.length - 1] = Math.pow(cur[cur.length - 1], 3);
    } else if (item === "#") {
      achaArray[curIdx]++;
    } else if (item === "*") {
      starArray[curIdx]++;
    }
  });

  achaArray.forEach((num, idx) => {
    if (num !== 0) {
      cur[idx] = -cur[idx];
    }
  });

  starArray.forEach((num, idx) => {
    if (num !== 0) {
      if (idx === 0) cur[idx] *= 2;
      else {
        cur[idx] *= 2;
        cur[idx - 1] *= 2;
      }
    }
  });

  return cur.reduce((acc, num) => acc + num);
}
