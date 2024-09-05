function solution(dots) {
  let y = [];
  let x = [];

  dots.map((item, index) => {
    x.push(item[0]);
    y.push(item[1]);
  });
  let xscale = Math.max(...x) - Math.min(...x);
  let yscale = Math.max(...y) - Math.min(...y);

  return xscale * yscale;
}
