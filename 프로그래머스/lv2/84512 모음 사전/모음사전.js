function solution(word) {
  var answer = 0;

  const arr = ["A", "E", "I", "O", "U"];

  const list = [];

  function DFS(str, cnt) {
    if (cnt <= 5) {
      list.push(str);
      for (let i = 0; i < 5; ++i) {
        DFS(str + arr[i], cnt + 1);
      }
    }
  }

  DFS("", 0);

  answer = list.indexOf(word);

  return answer;
}
