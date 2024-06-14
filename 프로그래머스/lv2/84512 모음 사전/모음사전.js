function solution(word) {
  const dict = ["A", "E", "I", "O", "U"];

  const list = [];

  function DFS(k, str) {
    if (k === 6) return;

    list.push(str);
    for (let i = 0; i < 5; ++i) {
      DFS(k + 1, str + dict[i]);
    }
  }

  DFS(0, "");

  return list.findIndex((item) => item === word);
}
