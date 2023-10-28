function solution(numer1, denom1, numer2, denom2) {
  let finaldemon = denom1 * denom2;
  let finalnumer = numer1 * denom2 + numer2 * denom1;

  let divisor = 2;
  while (divisor <= finaldemon) {
    if (finaldemon % divisor === 0 && finalnumer % divisor === 0) {
      finaldemon /= divisor;
      finalnumer /= divisor;
    } else {
      divisor++;
    }
  }
  return [finalnumer, finaldemon];
}
