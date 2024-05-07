function solution(board) {
  const directions = [
    [1, 0],
    [-1, 0],
    [0, -1],
    [0, 1],
  ];

  let robot = [0, 0];
  board = board.map((str, index) => {
    if (str.indexOf("R") !== -1) robot = [index, str.indexOf("R")];
    return str.split("");
  });

  const n = board.length;
  const m = board[0].length;

  const q = [[...robot, 0]];

  while (q.length) {
    const [x, y, cnt] = q.shift();

    if (board[x][y] === "G") {
      return cnt;
    }

    board[x][y] = "V";

    directions.forEach(([dx, dy]) => {
      let nextX = x;
      let nextY = y;

      while (
        nextX + dx >= 0 &&
        nextX + dx < n &&
        nextY + dy >= 0 &&
        nextY + dy < m &&
        board[nextX + dx]?.[nextY + dy] !== "D"
      ) {
        nextX += dx;
        nextY += dy;
      }
      if (board[nextX][nextY] === "G" || board[nextX][nextY] === ".") {
        q.push([nextX, nextY, cnt + 1]);
      }
    });
  }

  return -1;
}
