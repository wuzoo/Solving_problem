function solution(a, b) {
  let numer = a;
  let demon = b;

  let divisor = 2;
  while (divisor <= demon) {
    if (numer % divisor === 0 && demon % divisor === 0) {
      numer /= divisor;
      demon /= divisor;
    } else {
      ++divisor;
    }
  }
  while (demon % 2 === 0 || demon % 5 === 0) {
    if (demon % 2 === 0) demon /= 2;
    if (demon % 5 === 0) demon /= 5;
  }

  return demon === 1 ? 1 : 2;
}
