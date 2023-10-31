function solution(lines) {
  var answer = [];

  let doubleline = new Array(200).fill(0);

  lines.forEach((item) => {
    let start = item[0];
    let end = item[1];
    for (let i = start; i < end; ++i) {
      doubleline[i + 100]++;
    }
  });

  return doubleline.filter((v) => v >= 2).length;
}
