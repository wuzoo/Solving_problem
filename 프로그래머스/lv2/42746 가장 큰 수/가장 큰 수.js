function solution(numbers) {
  function compare(a, b) {
    return +(b.toString() + a.toString()) - +(a.toString() + b.toString());
  }

  numbers.sort((a, b) => compare(a, b));

  if (numbers[0] === 0) {
    return "0";
  }
  return numbers.join("");
}
