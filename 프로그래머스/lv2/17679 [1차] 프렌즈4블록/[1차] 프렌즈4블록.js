function solution(m, n, board) {
  var answer = 0;
  const arr = board.map((item) => item.split(""));

  while (true) {
    const block = [];
    for (let i = 0; i < m - 1; ++i) {
      for (let j = 0; j < n - 1; ++j) {
        const value = arr[i][j];
        if (
          value &&
          value === arr[i + 1][j] &&
          value === arr[i][j + 1] &&
          value === arr[i + 1][j + 1]
        ) {
          block.push([i, j]);
        }
      }
    }

    if (block.length === 0) break;

    block.forEach(([x, y]) => {
      arr[x][y] = 0;
      arr[x + 1][y] = 0;
      arr[x][y + 1] = 0;
      arr[x + 1][y + 1] = 0;
    });

    for (let i = 0; i < n; ++i) {
      let tmp = [];
      for (let j = 0; j < m; ++j) {
        if (arr[j][i] === 0) tmp.unshift(0);
        else tmp.push(arr[j][i]);
      }
      for (let j = 0; j < m; ++j) {
        arr[j][i] = tmp[j];
      }
    }
  }
  for (let i = 0; i < m; ++i) {
    for (let j = 0; j < n; ++j) {
      if (arr[i][j] === 0) {
        answer++;
      }
    }
  }

  return answer;
}
