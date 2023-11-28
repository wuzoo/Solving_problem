function isPrime(num) {
  let ok = true;
  for (let i = 2; i < num; ++i) {
    if (num % i === 0) {
      ok = false;
    }
  }
  return ok;
}

function solution(nums) {
  var answer = 0;

  let len = nums.length;

  for (let i = 0; i < len - 2; ++i) {
    let inum = nums[i];
    for (let j = i + 1; j < len - 1; ++j) {
      let jnum = nums[j];
      for (let k = j + 1; k < len; ++k) {
        let knum = nums[k];
        let cur = inum + jnum + knum;
        if (isPrime(cur)) {
          answer++;
        }
      }
    }
  }

  return answer;
}
