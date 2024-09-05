function solution(numbers) {
  let arr = new Array(10).fill(0).map((_, idx) => +idx);

  return arr
    .filter((v) => !numbers.includes(v))
    .reduce((acc, cur) => acc + cur, 0);
}
