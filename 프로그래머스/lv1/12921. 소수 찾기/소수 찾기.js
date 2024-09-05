function solution(n) {
  let nums = new Array(n + 1).fill(1);

  let iter = Math.sqrt(n);

  for (let i = 2; i < iter; ++i) {
    if (nums[i]) {
      for (let j = i ** 2; j <= n; j += i) {
        nums[j] = 0;
      }
    }
  }
  return nums.filter((v) => v !== 0).length - 2;
}
