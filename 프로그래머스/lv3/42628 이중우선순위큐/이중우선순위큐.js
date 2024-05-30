function solution(operations) {
  var answer = [];

  let idx = 0;
  operations.forEach((item) => {
    const [flag, number] = item.split(" ");

    if (flag === "I") {
      answer.push(+number);
      answer.sort((a, b) => a - b);
    } else if (item === "D -1") {
      if (idx < answer.length) {
        idx++;
      }
    } else if (item === "D 1") {
      answer.pop();
    }
  });
  answer = answer.sort((a, b) => a - b).slice(idx);

  return answer.length ? [answer.at(-1), answer.at(0)] : [0, 0];
}
