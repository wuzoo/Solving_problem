function solution(food) {
  var answer = "";

  food.forEach((num, idx) => {
    if (idx === 0) return;
    else {
      for (let i = 0; i < Math.floor(num / 2); ++i) {
        answer += idx;
      }
    }
  });
  answer +=
    "0" +
    answer
      .split("")
      .sort((a, b) => b - a)
      .join("");

  return answer;
}
