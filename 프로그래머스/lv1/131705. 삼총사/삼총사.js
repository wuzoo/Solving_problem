function solution(number) {
  var answer = 0;
  let len = number.length;

  for (let i = 0; i < len; ++i) {
    let inum = number[i];
    for (let j = i + 1; j < len; ++j) {
      let jnum = number[j];
      for (let k = j + 1; k < len; ++k) {
        if (inum + jnum + number[k] === 0) {
          answer++;
        }
      }
    }
  }

  return answer;
}
