function solution(tickets) {
  let answer = [];
  const visitMap = new Map();

  tickets.forEach((item, idx) => {
    const [start, end] = item;
    visitMap.set(start + end + idx, 0);
  });

  function DFS(k, arr = []) {
    if (k === tickets.length) {
      answer.push(arr);
      return;
    }
    for (let i = 0; i < tickets.length; ++i) {
      const [start, end] = tickets[i];

      if (arr.at(-1) !== start) continue;
      if (visitMap.get(start + end + i) === 1) continue;

      visitMap.set(start + end + i, 1);
      DFS(k + 1, [...arr, end]);
      visitMap.set(start + end + i, 0);
    }
  }
  DFS(0, ["ICN"]);

  answer = answer
    .map((arr) => arr.join(" "))
    .sort()
    .map((str) => str.split(" "));

  return answer[0];
}
