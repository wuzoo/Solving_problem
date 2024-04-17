function solution(queue1, queue2) {
  var answer = 0;

  const q1len = queue1.length,
    q2len = queue2.length;

  let sum1 = queue1.reduce((acc, cur) => acc + cur, 0);
  let sum2 = queue2.reduce((acc, cur) => acc + cur, 0);

  let idx1 = 0,
    idx2 = 0;
  while (sum1 !== sum2) {
    if (idx1 >= q1len && idx2 >= q2len) {
      answer = -1;
      break;
    }
    if (sum1 > sum2) {
      const abstractNum = queue1[idx1++];
      sum1 -= abstractNum;
      queue2.push(abstractNum);
      sum2 += abstractNum;
    } else if (sum1 < sum2) {
      const abstractNum = queue2[idx2++];
      sum2 -= abstractNum;
      queue1.push(abstractNum);
      sum1 += abstractNum;
    }
    answer++;
  }

  return answer;
}
