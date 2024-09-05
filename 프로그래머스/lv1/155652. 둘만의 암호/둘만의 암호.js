function solution(s, skip, index) {
  var answer = "";

  s.split("").forEach((letter) => {
    let count = 0;
    let tmp = letter.codePointAt();
    while (count < index) {
      tmp = ((tmp + 1 - 97) % 26) + 97;
      if (skip.includes(String.fromCharCode(tmp))) {
        continue;
      }
      ++count;
    }
    answer += String.fromCharCode(tmp);
  });

  return answer;
}
