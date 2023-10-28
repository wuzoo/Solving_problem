function isQuizRight(first, second, sign) {
  if (sign === "+") {
    return +first + +second;
  }
  if (sign === "-") {
    return +first - +second;
  }
}

function solution(quiz) {
  var answer = [];

  quiz.map((item) => {
    let arr = item.split(" ");
    if (+arr[4] === isQuizRight(arr[0], arr[2], arr[1])) {
      answer.push("O");
    } else {
      answer.push("X");
    }
  });

  return answer;
}
