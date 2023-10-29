function solution(A, B) {
  var answer = 0;

  let word = A;
  let len = word.length;
  let count = 0;
  while (len--) {
    if (word === B) {
      break;
    }
    word = word.slice(word.length - 1) + word.slice(0, word.length - 1);
    count++;
  }

  return count >= word.length ? -1 : count;
}
