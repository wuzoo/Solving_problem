const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const input = stdin[1].split(" ").map(Number);

function solution() {
  const dp = Array.from(Array(61), () =>
    Array.from(Array(61), () => Array(61).fill(0))
  );

  const arr = [];
  for (let i = 0; i < 3; ++i) {
    if (i + 1 > input.length) {
      arr.push(0);
    } else {
      arr.push(input[i]);
    }
  }

  const visited = Array.from({ length: 3 }, () => 0);
  const possibleAttack = [9, 3, 1];
  const attack = [];

  const makeAttack = (k, arr) => {
    if (k === N) {
      attack.push(arr);
      return;
    }
    for (let i = 0; i < N; ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        makeAttack(k + 1, [...arr, possibleAttack[i]]);
        visited[i] = 0;
      }
    }
  };

  makeAttack(0, []);

  const q = [[...arr, 0]];
  dp[arr[0]][arr[1]][arr[2]] = 0;

  while (q.length) {
    const [a, b, c, cnt] = q.shift();

    if (a === 0 && b === 0 && c === 0) {
      break;
    }
    for (let i = 0; i < attack.length; ++i) {
      const [one, two, three] = attack[i];

      let nexta = a - one > 0 ? a - one : 0;
      let nextb = b - two > 0 ? b - two : 0;
      let nextc = c - three > 0 ? c - three : 0;

      if (dp[nexta][nextb][nextc] === 0) {
        dp[nexta][nextb][nextc] = dp[a][b][c] + 1;
        q.push([nexta, nextb, nextc, cnt + 1]);
      }
    }
  }

  console.log(dp[0][0][0]);
}

solution();
