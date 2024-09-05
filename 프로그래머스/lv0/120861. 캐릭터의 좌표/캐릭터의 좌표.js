function solution(keyinput, board) {
  let xlimit = [-Math.floor(board[0] / 2), Math.floor(board[0] / 2)];
  let ylimit = [-Math.floor(board[1] / 2), Math.floor(board[1] / 2)];

  var curpoint = {
    x: 0,
    y: 0,
    move(order) {
      switch (order) {
        case "left":
          if (this.x > xlimit[0]) this.x--;
          break;
        case "right":
          if (this.x < xlimit[1]) this.x++;
          break;
        case "up":
          if (this.y < ylimit[1]) this.y++;
          break;
        case "down":
          if (this.y > ylimit[0]) this.y--;
      }
    },
  };
  keyinput.map((item) => {
    curpoint.move(item);
  });

  return [curpoint.x, curpoint.y];
}
