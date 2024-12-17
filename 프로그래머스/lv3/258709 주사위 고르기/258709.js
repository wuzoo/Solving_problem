function solution(dice) {
  var answer = [];
  const n = dice.length;
  const visited = new Array(11).fill(0);

  const aCase = [];
  const bCase = [];

  let mx = -Infinity;
  function dfs(k, idx, arr) {
    if (k == n / 2) {
      const brr = [];
      for (let i = 1; i <= n; ++i) {
        if (!arr.includes(i)) {
          brr.push(i);
        }
      }
      aCase.push(arr);
      bCase.push(brr);
    }
    for (let i = idx; i <= n; ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        arr.push(i);
        dfs(k + 1, i, [...arr]);
        arr.pop();
        visited[i] = 0;
      }
    }
  }

  dfs(0, 1, []);

  for (let i = 0; i < aCase.length; ++i) {
    let atmp = [];
    let btmp = [];

    aCase[i].forEach((num) => {
      let arr = dice[num - 1];

      if (atmp.length == 0) {
        atmp = arr;
      } else {
        const tmp = [];
        atmp.forEach((num1) => {
          arr.forEach((num2) => {
            tmp.push(num1 + num2);
          });
        });
        atmp = tmp;
      }
    });

    bCase[i].forEach((num) => {
      const arr = dice[num - 1];

      if (btmp.length == 0) {
        btmp = arr;
      } else {
        const tmp = [];
        btmp.forEach((num1) => {
          arr.forEach((num2) => {
            tmp.push(num1 + num2);
          });
        });
        btmp = tmp;
      }
    });

    const map = new Map();

    let aWin = 0;

    for (let j = 0; j < atmp.length; ++j) {
      let cnt = 0;

      if (map.has(atmp[j])) {
        aWin += map.get(atmp[j]);
        continue;
      }

      for (let k = 0; k < btmp.length; ++k) {
        if (atmp[j] > btmp[k]) cnt++;
      }

      map.set(atmp[j], cnt);
      aWin += cnt;
    }

    if (mx < aWin) {
      answer = aCase[i];
      mx = aWin;
    }
  }

  return answer;
}
