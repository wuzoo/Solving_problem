function solution(s) {
  var answer = [];

  let iterCnt = 0;
  let zeroCnt = 0;
  while (true) {
    if (s === "1") {
      break;
    }
    iterCnt++;
    const num = s.split("").filter((item) => {
      if (item === "0") {
        zeroCnt++;
      }
      return item !== "0";
    });
    s = num.length.toString(2);
  }

  return [iterCnt, zeroCnt];
}
