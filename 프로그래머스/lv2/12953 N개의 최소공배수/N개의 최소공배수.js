function solution(arr) {
  let value = arr[0];
  for (let i = 1; i < arr.length; ++i) {
    value = lcm(value, arr[i]);
  }

  return value;
}

function gcd(a, b) {
  let remain = a % b;
  if (remain === 0) return b;

  return gcd(b, remain);
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}
