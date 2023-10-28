function solution(num, total) {
  var answer = [];

  let tmp = Math.floor(total / 2);
  while (true) {
    let arr = [];
    for (let i = 0; i < num; ++i) {
      arr.push(tmp - i);
    }
    let result = arr.reduce((arr, cur) => arr + cur, 0);
    if (result === total) {
      return arr.sort((a, b) => a - b);
    }
    if (result > total) {
      --tmp;
    } else {
      ++tmp;
    }
  }
}
