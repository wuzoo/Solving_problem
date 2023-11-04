function solution(number, limit, power) {
  var answer = 0;

  const arr = new Array(number).fill(0).map((_, idx) => idx + 1);
  arr.forEach((number) => {
    let icount = 0;
    for (let i = 1; i < Math.sqrt(number); ++i) {
      if (number % i === 0) {
        icount++;
      }
    }
    icount = icount * 2 + Number.isInteger(Math.sqrt(number));

    answer += icount > limit ? power : icount;
  });

  return answer;
}
