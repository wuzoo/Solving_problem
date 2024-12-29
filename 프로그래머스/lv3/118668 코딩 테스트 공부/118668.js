let targetAlp = 0;
let targetCop = 0;

function solution(alp, cop, problems) {
  function DFS(a, c, cnt, problems) {
    if (targetAlp < a) a = targetAlp;
    if (targetCop < c) c = targetCop;

    if (visit[a][c] <= cnt) return;

    visit[a][c] = Math.min(visit[a][c], cnt);

    if (a === targetAlp && c === targetCop) return;

    for (let i = 0; i < problems.length; ++i) {
      if (a >= problems[i][0] && c >= problems[i][1]) {
        let nextAlp = a + problems[i][2];
        let nextCop = c + problems[i][3];
        DFS(nextAlp, nextCop, cnt + problems[i][4], problems);
      }
    }

    DFS(a + 1, c, cnt + 1, problems);
    DFS(a, c + 1, cnt + 1, problems);
  }

  let answer = 0;
  const visit = [];
  for (let i = 0; i < 151; ++i) {
    const temp = [];
    for (let j = 0; j < 151; ++j) {
      temp.push(Infinity);
    }
    visit.push(temp);
  }

  for (let i = 0; i < problems.length; ++i) {
    targetAlp = Math.max(targetAlp, problems[i][0]);
    targetCop = Math.max(targetCop, problems[i][1]);
  }

  DFS(alp, cop, 0, problems);

  answer = visit[targetAlp][targetCop];
  return answer;
}
