function solution(common) {
  var answer = 0;

  let plus = common[1] - common[1 - 1];
  let mult1 = common[1] / common[1 - 1];

  let isPlus = true;
  for (let i = 1; i < common.length; ++i) {
    if (common[i] - common[i - 1] !== plus) {
      isPlus = false;
    }
  }
  let len = common.length;
  answer = isPlus ? common[len - 1] + plus : common[len - 1] * mult1;

  return answer;
}
