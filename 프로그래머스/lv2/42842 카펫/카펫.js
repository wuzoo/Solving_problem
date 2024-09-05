function solution(brown, yellow) {
  var answer = [];

  for (let i = 3; i <= brown / 2; ++i) {
    for (let j = 1; j <= brown / 2; ++j) {
      const bCnt = 2 * (i + j) - 4;
      if (bCnt === brown && i * j - bCnt === yellow) {
        if (i < j) break;

        answer.push(i);
        answer.push(j);
      }
    }
  }

  return answer;
}
