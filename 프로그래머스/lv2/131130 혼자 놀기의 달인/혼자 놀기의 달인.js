function solution(cards) {
  const parent = new Array(cards.length + 1).fill(0);
  const result = new Array(cards.length + 1).fill(0);
  cards.unshift(0);

  function Find(x) {
    if (x === parent[x]) return x;
    return (parent[x] = Find(parent[x]));
  }

  function Union(x, y) {
    x = Find(x);
    y = Find(y);

    if (x === y) return;

    if (x < y) parent[y] = x;
    else parent[x] = y;
  }

  for (let i = 1; i < cards.length; ++i) {
    parent[i] = i;
  }

  for (let i = 1; i < cards.length; ++i) {
    Union(cards[i], cards[cards[i]]);
  }

  for (let i = 1; i < cards.length; ++i) {
    const root = Find(cards[i]);
    result[root]++;
  }

  result.sort((a, b) => b - a);

  if (result.filter((item) => item !== 0).length > 1) {
    return result[0] * result[1];
  }

  return 0;
}

// function solution(cards) {
//   var answer = 0;
//   const visited = new Array(cards.length + 1).fill(0);
//   cards.unshift(0);

//   function DFS(index) {
//     let count = 1;

//     visited[index] = 1;
//     const next = cards[index];

//     if (visited[next]) return 0;

//     count += DFS(next);

//     return count;
//   }

//   let result = [];

//   for (let i = 1; i < cards.length; ++i) {
//     let firstMap = DFS(i) + 1;
//     result.push(firstMap);

//     while (true) {
//       const j = visited.findIndex((item, idx) => item === 0 && idx >= 1);
//       if (j === -1) break;

//       const cnt = DFS(j) + 1;
//       result.push(cnt);
//     }

//     result.sort((a, b) => b - a);
//     answer = Math.max(answer, result.length === 1 ? 0 : result[0] * result[1]);
//     visited.fill(0);
//     result = [];
//   }

//   return answer;
// }
