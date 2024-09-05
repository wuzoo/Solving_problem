function solution(sizes) {
  let rotated = sizes.map(([w, h]) => (h > w ? [h, w] : [w, h]));

  let maxw = 0;
  let maxh = 0;
  rotated.forEach(([w, h]) => {
    if (w > maxw) maxw = w;
    if (h > maxh) maxh = h;
  });

  return maxw * maxh;
}
