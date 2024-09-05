function solution(board) {
  const dx = [0, 0, -1, 1];
  const dy = [1, -1, 0, 0];

  const n = board.length;

  const distance = Array.from(Array(n), () =>
    Array.from({ length: n }, () => [Infinity, Infinity])
  );

  const q = [[0, 0, 0, -1]];

  while (q.length) {
    const [x, y, cost, route] = q.shift();

    if (distance[x][y][route] < cost) continue;

    for (let i = 0; i < 4; ++i) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (board[nx][ny] === 1) continue;

      let newPrice = cost + 100;

      if (route !== -1 && ((route === 0 && i < 2) || (route === 1 && i >= 2))) {
        newPrice += 500;
      }

      if (i < 2) {
        if (newPrice < distance[nx][ny][1]) {
          q.push([nx, ny, newPrice, 1]);
          q.sort((a, b) => a[2] - b[2]);
          distance[nx][ny][1] = newPrice;
        }
      }
      if (i >= 2) {
        if (newPrice < distance[nx][ny][0]) {
          q.push([nx, ny, newPrice, 0]);
          q.sort((a, b) => a[2] - b[2]);
          distance[nx][ny][0] = newPrice;
        }
      }
    }
  }

  return Math.min(...distance[n - 1][n - 1]);
}
