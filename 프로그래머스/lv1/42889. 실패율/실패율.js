function solution(N, stages) {
  let answer = [];

  let notclear = new Array(N + 1).fill(0);
  let clear = new Array(N + 1).fill(0);

  stages.forEach((item, idx) => {
    notclear[item]++;
    for (let i = item; i > 0; --i) {
      clear[i]++;
    }
  });

  let stage = [];
  for (let i = 1; i <= N; ++i) {
    if (clear[i] === 0) stage.push([i, 0]);
    else stage.push([i, parseFloat(notclear[i] / clear[i])]);
  }
  stage.sort((a, b) => b[1] - a[1]);

  return stage.map((item) => item[0]);
}
