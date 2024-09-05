function compare(str1, str2) {
  let cnt = 0;
  for (let i = 0; i < str1.length; ++i) {
    if (str1[i] !== str2[i]) cnt++;
  }
  return cnt;
}

function solution(begin, target, words) {
  var answer = 51;
  const visited = new Array(words.length).fill(0);

  if (!words.includes(target)) return 0;

  function DFS(k, str) {
    if (str === target) {
      answer = Math.min(answer, k);
      return;
    }
    for (let i = 0; i < words.length; ++i) {
      if (!visited[i] && compare(str, words[i]) === 1) {
        visited[i] = 1;
        DFS(k + 1, words[i]);
        visited[i] = 0;
      }
    }
  }

  DFS(0, begin);

  return answer;
}
