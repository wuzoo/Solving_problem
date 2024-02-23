function solution(n) {
  var answer = 0;

  const originLen = n
    .toString(2)
    .split("")
    .filter((item) => item === "1").length;

  while (true) {
    const next = ++n;

    const nextLen = next
      .toString(2)
      .split("")
      .filter((item) => item === "1").length;

    if (nextLen === originLen) {
      answer = next;
      break;
    }
  }

  return answer;
}
