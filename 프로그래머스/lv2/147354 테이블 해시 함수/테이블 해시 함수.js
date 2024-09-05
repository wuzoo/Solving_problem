function solution(data, col, row_begin, row_end) {
  data.sort((a, b) => a[col - 1] - b[col - 1] || b[0] - a[0]);

  const s_i = [];
  for (let i = row_begin; i <= row_end; ++i) {
    s_i.push(data[i - 1].reduce((acc, cur) => acc + (cur % i), 0));
  }

  return s_i.reduce((acc, cur) => acc ^ cur, 0);
}
