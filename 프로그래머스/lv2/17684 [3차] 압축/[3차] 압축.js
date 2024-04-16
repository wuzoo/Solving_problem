function solution(msg) {
  const answer = [];
  const dict = new Array(27).fill(0).map((_, i) => String.fromCharCode(i + 64));

  let tmp = "";
  for (let i = 0; i < msg.length; ++i) {
    if (dict.includes(tmp + msg[i])) {
      tmp += msg[i];
    } else {
      answer.push(dict.indexOf(tmp));
      dict.push(tmp + msg[i]);
      i--;
      tmp = "";
    }
  }
  answer.push(dict.indexOf(tmp));

  return answer;
}
