// DFS
function solution(maps) {
  var answer = [];

  const dx = [0, 0, -1, 1];
  const dy = [1, -1, 0, 0];
  const n = maps.length; // y
  const m = maps[0].length; // x

  const graph = maps.map((item) => item.split(""));
  const visited = Array.from(Array(n), () => Array(m).fill(0));

  function DFS(x, y) {
    let cnt = +graph[x][y];
    visited[x][y] = 1;
    for (let i = 0; i < 4; ++i) {
      let nx = x + dx[i];
      let ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (visited[nx][ny]) continue;
      if (graph[nx][ny] === "X") continue;

      visited[nx][ny] = 1;
      cnt += DFS(nx, ny);
    }
    return cnt;
  }

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      if (!visited[i][j] && graph[i][j] !== "X") {
        const count = DFS(i, j);
        answer.push(count);
      }
    }
  }

  return answer.length ? answer.sort((a, b) => a - b) : [-1];
}

// BFS
function solution(maps) {
  var answer = [];

  const dx = [0, 0, -1, 1];
  const dy = [1, -1, 0, 0];
  const n = maps.length; // y
  const m = maps[0].length; // x

  const graph = maps.map((item) => item.split(""));
  const visited = Array.from(Array(n), () => Array(m).fill(0));

  function BFS(x, y) {
    const q = [[x, y, graph[x][y]]];
    visited[x][y] = 1;
    let sum = 0;
    while (q.length) {
      let [x, y, cnt] = q.shift();
      sum += +cnt;

      for (let i = 0; i < 4; ++i) {
        let nx = x + dx[i];
        let ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!visited[nx][ny] && graph[nx][ny] !== "X") {
          visited[nx][ny] = 1;
          q.push([nx, ny, graph[nx][ny]]);
        }
      }
    }
    return sum;
  }

  for (let i = 0; i < n; ++i) {
    for (let j = 0; j < m; ++j) {
      if (!visited[i][j] && graph[i][j] !== "X") {
        const count = BFS(i, j);
        answer.push(count);
      }
    }
  }

  return answer.length ? answer.sort((a, b) => a - b) : [-1];
}
