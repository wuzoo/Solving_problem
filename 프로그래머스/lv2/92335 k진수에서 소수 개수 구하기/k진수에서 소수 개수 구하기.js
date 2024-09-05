function solution(n, k) {
  var answer = 0;

  const converted = n.toString(k);

  converted.split("0").forEach((item) => {
    if (+item === 1 || +item === 0) return;
    else if (isPrimeNumber(+item)) answer++;
  });

  return answer;
}

function isPrimeNumber(x) {
  let end = Math.sqrt(x);
  for (let i = 2; i <= end; ++i) {
    if (x % i === 0) return false;
  }
  return true;
}
