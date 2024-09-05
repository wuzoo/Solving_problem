function solution(n, k) {
  var answer = [];

  const num = new Array(n).fill(0).map((_, i) => i + 1);

  function factorial(n) {
    let sum = 1;
    for (let i = n; i >= 2; --i) {
      sum *= i;
    }
    return sum;
  }

  let knum = k;
  while (num.length > 1) {
    let r = knum % factorial(num.length - 1);
    let q = Math.floor(knum / factorial(num.length - 1));

    if (r === 0) {
      answer.push(num[q - 1]);
      num.splice(q - 1, 1);
      num.sort((a, b) => b - a).forEach((item) => answer.push(item));
      break;
    } else if (r === 1) {
      answer.push(num[q]);
      num.splice(q, 1);
      num.forEach((item) => answer.push(item));
      break;
    } else {
      answer.push(num[q]);
      num.splice(q, 1);
      knum = r;
    }
  }

  return answer;
}
