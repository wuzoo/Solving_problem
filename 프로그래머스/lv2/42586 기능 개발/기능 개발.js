function solution(progresses, speeds) {
  var answer = [];

  let num = 0;
  let iter = 1;
  while (true) {
    if (progresses.length === 0) {
      break;
    }

    for (let i = 0; i < progresses.length; ++i) {
      const value = progresses[i] + iter * speeds[i];
      if (value < 100) {
        break;
      } else if (value >= 100) {
        num++;
      }
    }
    iter++;
    if (num === 0) continue;

    answer.push(num);
    progresses.splice(0, num);
    speeds.splice(0, num);
    num = 0;
  }

  return answer;
}
