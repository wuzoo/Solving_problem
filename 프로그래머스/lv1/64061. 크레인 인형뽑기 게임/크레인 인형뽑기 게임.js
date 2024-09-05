function solution(board, moves) {
  var answer = 0;

  let 바구니 = [];
  let len = board.length;

  moves.map((item, idx) => {
    if (board[len - 1][item - 1] === 0) return;
    for (let i = 0; i < len; ++i) {
      if (board[i][item - 1] !== 0) {
        if (바구니[바구니.length - 1] === board[i][item - 1]) {
          board[i][item - 1] = 0;
          바구니.pop();
          answer += 2;
        } else {
          바구니.push(board[i][item - 1]);
          board[i][item - 1] = 0;
        }
        break;
      }
    }
  });

  return answer;
}
