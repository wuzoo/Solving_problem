function solution(players, callings) {
  let playermap = new Map();

  players.forEach((players, idx) => {
    playermap.set(players, idx); // string, number
  });
  callings.map((item) => {
    let idx = playermap.get(item); // 현재 호출된 선수 이름의 idx
    let tmp = players[idx - 1];

    players[idx - 1] = item;
    players[idx] = tmp;

    playermap.set(item, idx - 1);
    playermap.set(tmp, idx);
  });

  return players;
}
