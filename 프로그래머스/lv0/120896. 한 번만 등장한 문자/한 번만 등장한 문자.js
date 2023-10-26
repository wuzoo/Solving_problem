function solution(s) {
  let answer = [];
  let arr = new Array(26).fill(0);

  s.split("").map((item) => arr[item.codePointAt() - 97]++);

  arr.map((item, index) => {
    if (item === 1) {
      answer.push(String.fromCharCode(97 + index));
    }
  });
  return answer.sort().join("");
}
