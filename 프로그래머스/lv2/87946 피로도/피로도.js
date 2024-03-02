function solution(k, dungeons) {
  var answer = -1;

  const visited = new Array(dungeons.length).fill(0);

  function DFS(k, count) {
    for (let i = 0; i < dungeons.length; ++i) {
      if (!visited[i]) {
        if (dungeons[i][0] > k) continue;
        visited[i] = 1;
        DFS(k - dungeons[i][1], count + 1);
        visited[i] = 0;
      }
    }
    answer = Math.max(answer, count);
  }

  DFS(k, 0);

  return answer;
}
