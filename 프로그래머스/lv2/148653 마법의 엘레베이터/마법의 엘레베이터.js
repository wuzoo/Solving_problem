function solution(storey) {
  let answer = 0;
  const arr = storey
    .toString()
    .split("")
    .reverse()
    .map((str) => +str);

  arr.forEach((num, idx) => {
    if (num < 5) {
      answer += num;
    } else if (num > 5) {
      answer += 10 - num;
      if (idx + 1 < arr.length) {
        arr[idx + 1]++;
      } else {
        answer++;
      }
    } else if (num === 5) {
      answer += num;
      if (idx + 1 < arr.length && arr[idx + 1] >= 5) {
        arr[idx + 1]++;
      }
    }
  });

  return answer;
}
