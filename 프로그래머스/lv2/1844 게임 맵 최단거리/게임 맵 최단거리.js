function solution(maps) {
  const dx = [0, 0, -1, 1];
  const dy = [1, -1, 0, 0];

  const n = maps.length;
  const m = maps[0].length;

  const visited = Array.from(Array(n), () => Array(m).fill(0));

  const q = [[0, 0, 1]];
  visited[0][0] = 1;

  while (q.length) {
    let [x, y, cnt] = q.shift();

    if (x === n - 1 && y === m - 1) return cnt;

    for (let i = 0; i < 4; ++i) {
      let nx = x + dx[i];
      let ny = y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        if (maps[nx][ny] === 0) continue;
        if (!visited[nx][ny]) {
          visited[nx][ny] = 1;
          q.push([nx, ny, cnt + 1]);
        }
      }
    }
  }

  return -1;
}
