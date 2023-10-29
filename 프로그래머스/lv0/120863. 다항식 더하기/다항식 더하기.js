function solution(polynomial) {
  let regexp = /\d*x/g;
  let constexp = /\d+[^x]/g;

  let xsum = 0;
  let sum = 0;
  polynomial.split(" + ").map((item) => {
    if (item.match(regexp)) {
      xsum += item.length === 1 ? 1 : +item.slice(0, item.length - 1);
    } else {
      sum += +item.trim();
    }
  });
  let answer = [];
  if (xsum) answer.push(`${xsum === 1 ? "" : xsum}x`);
  if (sum) answer.push(`${sum}`);
  return answer.join(" + ");
}
