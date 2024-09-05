const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const [N, M] = stdin[0].split(" ").map(Number);
const arr = stdin[1].split(" ").map(Number);

let knowing = arr.slice(1);

const parties = stdin
  .slice(2)
  .map((str) => str.split(" ").map(Number))
  .map((arr) => arr.slice(1));

function solution() {
  const parent = new Array(N + 1).fill(0);

  function FindParent(x) {
    if (x === parent[x]) return x;
    return (parent[x] = FindParent(parent[x]));
  }

  function Union(x, y) {
    x = FindParent(x);
    y = FindParent(y);

    if (x === y) return;

    if (x < y) {
      parent[y] = x;
    } else {
      parent[x] = y;
    }
  }

  for (let i = 1; i <= N; ++i) {
    parent[i] = i;
  }

  parties.forEach((party) => {
    for (let i = 0; i < party.length - 1; ++i) {
      Union(party[i], party[i + 1]); // 파티 참여자 중 가장 작은 넘버 기준으로 부모
    }
  });

  let answer = 0;

  parties.forEach((party) => {
    party.sort((a, b) => a - b);

    const canLie = !knowing.some(
      (num) => FindParent(party[0]) === FindParent(num)
    );

    if (canLie) answer++;
  });

  console.log(answer);
}

solution();
