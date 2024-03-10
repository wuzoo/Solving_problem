function solution(order) {
  const subConveyor = [];
  const truck = [];
  const conveyor = new Array(order.length).fill(0).map((_, i) => i + 1);

  let index = 0;
  let cnt = 0;

  while (conveyor.length || subConveyor.length) {
    const current = index < conveyor.length ? conveyor[index] : -1;
    const subCurrent = subConveyor.length
      ? subConveyor[subConveyor.length - 1]
      : -1;

    if (current === order[cnt]) {
      cnt++;
      index++;
      truck.push(current);
    } else if (subCurrent === order[cnt]) {
      cnt++;
      truck.push(subCurrent);
      subConveyor.pop();
    } else {
      if (current === -1) break;
      index++;
      subConveyor.push(current);
    }
  }

  return truck.length;
}
