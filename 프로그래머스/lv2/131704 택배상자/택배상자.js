function solution(order) {
  const truck = [];
  const boxArray = new Array(order.length)
    .fill(0)
    .map((_, i) => i + 1)
    .reverse();
  const subArray = [];

  let idx = 0;
  while ((boxArray.length || subArray.length) && idx < order.length) {
    if (boxArray.at(-1) === order[idx]) {
      truck.push(boxArray.pop());
      idx++;
    } else if (subArray.at(-1) === order[idx]) {
      truck.push(subArray.pop());
      idx++;
    } else {
      if (!boxArray.length) break;
      subArray.push(boxArray.pop());
    }
  }

  return truck.length;
}
