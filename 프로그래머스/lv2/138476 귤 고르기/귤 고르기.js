function solution(k, tangerine) {
  var answer = 0;

  tangerine.sort((a, b) => a - b);
  const map = new Map();

  for (let i = 0; i < tangerine.length; ++i) {
    if (map.has(tangerine[i])) {
      map.set(tangerine[i], map.get(tangerine[i]) + 1);
    } else {
      map.set(tangerine[i], 1);
    }
  }

  const temp = [];
  for (let [key, value] of map) {
    temp.push(value);
  }
  temp.sort((a, b) => b - a);

  let sum = 0;
  for (let i = 0; i < temp.length; ++i) {
    sum += temp[i];
    if (sum >= k) {
      answer = i + 1;
      break;
    }
  }

  return answer;
}
