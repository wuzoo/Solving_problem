function solution(s) {
  var answer = 0;

  let count = 0;

  let firstletter;
  s.split("").map((item, idx) => {
    if (count === 0) {
      firstletter = s[idx];
      answer++;
      count = 1;
    } else {
      if (firstletter === s[idx]) {
        count++;
      } else {
        count--;
      }
    }
  });

  return answer;
}
