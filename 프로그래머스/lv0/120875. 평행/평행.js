function solution(dots) {
  var answer = 0;

  let cmpdots = [
    [0, 1],
    [0, 2],
    [0, 3],
    [1, 2],
    [1, 3],
    [2, 3],
  ];

  cmpdots.map((item) => {
    let linex = dots[item[0]][0] - dots[item[1]][0];
    let liney = dots[item[0]][1] - dots[item[1]][1];

    let otherx = [];
    let othery = [];
    for (let i = 0; i < 4; ++i) {
      if (i !== item[0] && i !== item[1]) {
        otherx.push(dots[i][0]);
        othery.push(dots[i][1]);
      }
    }
    if (linex * (othery[1] - othery[0]) === liney * (otherx[1] - otherx[0])) {
      answer = 1;
      return;
    }
  });

  return answer;
}
