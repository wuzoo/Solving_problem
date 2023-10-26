function idxChanger(idx, size) {
  return idx % size;
}
function solution(numbers, k) {
  let size = numbers.length;

  let idx = 0;
  for (let i = 0; i < k - 1; ++i) {
    idx = idxChanger(idx + 2, size);
  }

  return numbers[idx];
}
