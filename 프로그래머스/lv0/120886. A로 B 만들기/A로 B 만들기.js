function solution(before, after) {
  var answer = 0;

  let arrb = before.split("").sort().join("");
  let arra = after.split("").sort().join("");

  answer = arrb === arra ? 1 : 0;

  return answer;
}
