function solution(arrayA, arrayB) {
  var answer = 0;

  arrayA.sort((a, b) => a - b);
  arrayB.sort((a, b) => a - b);

  const find = (cur, opp) => {
    let min = cur.at(0);
    for (let i = min; i >= 1; --i) {
      if (
        cur.every((item) => item % i === 0) &&
        !opp.some((item) => item % i === 0)
      ) {
        return i;
      }
    }
    return 0;
  };

  return Math.max(find(arrayA, arrayB), find(arrayB, arrayA));
}
