const MAP = {
  E: [1, 0],
  W: [-1, 0],
  S: [0, 1],
  N: [0, -1],
};

function solution(park, routes) {
  park = park.map((str) => str.split(""));

  let current = [0, 0];

  park.forEach((row, i1) => {
    row.forEach((col, i2) => {
      if (col === "S") current = [i2, i1];
    });
  });

  const m = park.length;
  const n = park[0].length;

  function canGo(side, step, pos = []) {
    let [x, y] = pos;
    for (let i = 0; i < step; ++i) {
      x += MAP[side][0];
      y += MAP[side][1];

      if (x < 0 || x >= n || y < 0 || y >= m || park[y][x] === "X")
        return false;
    }
    return true;
  }

  routes.forEach((item) => {
    const [side, step] = item.split(" ");

    if (canGo(side, +step, current)) {
      const dx = current[0] + MAP[side][0] * +step;
      const dy = current[1] + MAP[side][1] * +step;

      current = [dx, dy];
    }
  });

  return current.reverse();
}
