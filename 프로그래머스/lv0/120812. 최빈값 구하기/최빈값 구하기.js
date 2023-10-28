function solution(array) {
  var answer = 0;

  let arr = new Array(1000).fill(0);

  array.map((item) => arr[item]++);

  let mx = 0;
  arr.map((item, index) => {
    if (mx !== 0 && mx === item) {
      answer = -1;
      return;
    }
    if (item > mx) {
      answer = index;
      mx = item;
    }
  });

  return answer;
}
