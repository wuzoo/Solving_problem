function solution(user_id, banned_id) {
  const visited = new Array(user_id.length).fill(0);
  const result = [];
  const regexp = banned_id.map(
    (id) => new RegExp(`^${id.replaceAll("*", ".")}$`)
  );

  function DFS(k, arr) {
    if (k === banned_id.length) {
      result.push(arr.sort().join(""));
      return;
    }
    for (let i = 0; i < user_id.length; ++i) {
      if (!visited[i]) {
        if (user_id[i].match(regexp[k])) {
          visited[i] = 1;
          DFS(k + 1, [...arr, user_id[i]]);
          visited[i] = 0;
        }
      }
    }
  }

  DFS(0, []);

  return [...new Set(result)].length;
}
