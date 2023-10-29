function solution(numlist, n) {
  var answer = [];

  let tmparr = [];
  numlist.map((item) => {
    let arr = [];
    arr.push(Math.abs(item - n));
    arr.push(item);
    tmparr.push(arr);
  });
  // [절댓값, 실제 원소]
  tmparr.sort((a, b) => a[0] - b[0] || b[1] - a[1]);
  return tmparr.map((item) => item[1]);
}
