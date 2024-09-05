function solution(n, m, section) {
  let count = 0;

  let canreach = 0;
  section.forEach((num, idx) => {
    if (num <= canreach) return;
    canreach = num + m - 1;
    count++;
  });

  return count;
}
