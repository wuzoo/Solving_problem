function solution(msg) {
  var answer = [];

  const arr = [null];

  for (let i = 65; i <= 90; ++i) {
    arr.push(String.fromCharCode(i));
  }

  let tmp = "";
  for (let i = 0; i < msg.length; ++i) {
    if (arr.includes(tmp + msg[i])) {
      tmp += msg[i];
      continue;
    } else {
      answer.push(arr.indexOf(tmp));
      arr.push(tmp + msg[i]);
      i--;
      tmp = "";
    }
  }
  answer.push(arr.indexOf(tmp));

  return answer;
}
