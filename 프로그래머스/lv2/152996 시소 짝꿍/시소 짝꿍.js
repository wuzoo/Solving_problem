function solution(weights) {
  let answer = 0;
  let count = 0;

  const arr = new Array(4001).fill(0);
  let prevWeight = 0;

  weights.sort();
  weights.forEach((num) => {
    arr[num * 2]++;
    arr[num * 3]++;
    arr[num * 4]++;

    if (prevWeight === num) {
      count++;
      answer -= count * 2;
    } else {
      prevWeight = num;
      count = 0;
    }
  });

  arr.forEach((cnt) => {
    if (cnt > 1) {
      let sum = 0;
      for (let i = 1; i < cnt; ++i) {
        sum += i;
      }
      answer += sum;
    }
  });

  return answer;
}
