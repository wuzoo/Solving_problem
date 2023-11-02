function solution(wallpaper) {
  let map = [];
  wallpaper.map((item) => {
    map.push(item.split(""));
  });

  let startx = [];
  let starty = [];
  let endx = [];
  let endy = [];
  map.forEach((row, rowidx) => {
    // rowidx : x, colidx: y
    row.map((col, colidx) => {
      if (col === "#") {
        startx.push(rowidx);
        starty.push(colidx);
        endx.push(rowidx + 1);
        endy.push(colidx + 1);
      }
    });
  });
  return [
    Math.min(...startx),
    Math.min(...starty),
    Math.max(...endx),
    Math.max(...endy),
  ];
}
