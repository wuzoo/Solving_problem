function solution(storey) {
  var answer = 0;

  const arr = storey
    .toString()
    .split("")
    .reverse()
    .map((str) => +str);

  for (let i = 0; i < arr.length; ++i) {
    if (arr[i] < 5) {
      answer += arr[i];
    } else if (arr[i] > 5) {
      answer += 10 - arr[i];
      if (i + 1 < arr.length) {
        arr[i + 1]++;
      } else {
        answer++;
      }
    } else if (arr[i] === 5) {
      answer += arr[i];

      if (arr[i + 1] >= 5 && i + 1 < arr.length) {
        arr[i + 1]++;
      }
    } else {
      return -1;
    }
  }

  return answer;
}
