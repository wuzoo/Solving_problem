function solution(board) {
  let dx = [0, -1, -1, -1, 0, 1, 1, 1];
  let dy = [1, 1, 0, -1, -1, -1, 0, 1];

  board.map((row, idxs) => {
    row.map((col, idx) => {
      if (col === 1) {
        let x = idxs;
        let y = idx;
        for (let i = 0; i < 8; ++i) {
          let nx = x + dx[i];
          let ny = y + dy[i];
          if (nx >= 0 && nx < board.length && ny >= 0 && ny < board.length) {
            if (board[nx][ny] === 0 && board[nx][ny] !== 1) board[nx][ny] = 2;
          }
        }
      }
    });
  });
  return board.reduce(
    (acc, item) => item.filter((v) => v === 0).length + acc,
    0
  );
}
