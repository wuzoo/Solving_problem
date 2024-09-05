function solution(s) {
  const tmp = JSON.parse(s.replace(/\{/g, "[").replace(/\}/g, "]"));

  tmp.sort((a, b) => a.length - b.length);

  const answer = tmp.reduce((acc, cur) => acc.concat(cur), []);
  return [...new Set(answer)];
}
