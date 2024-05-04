function solution(places) {
  var answer = [];

  const dx = [0, 0, -1, 1];
  const dy = [1, -1, 0, 0];

  let map = [];
  places.forEach((place) => {
    const participants = [];

    place.forEach((item, row) => {
      for (let i = 0; i < item.length; ++i) {
        if (item[i] === "P") {
          participants.push([row, i]);
        }
      }
    });

    map = place.map((item) => item.split(""));

    let isSafe = true;
    participants.forEach(([x, y]) => {
      for (let i = 0; i < 4; ++i) {
        const nx = x + dx[i];
        const ny = y + dy[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || map[nx][ny] === "X")
          continue;

        if (map[nx][ny] === "P" || map[nx][ny] === "B") {
          isSafe = false;
          break;
        }

        map[nx][ny] = "B";
      }
    });

    answer.push(isSafe ? 1 : 0);
  });

  return answer;
}
