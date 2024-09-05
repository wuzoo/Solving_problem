function solution(n, costs) {
  const arr = new Array(n);

  function getParent(x) {
    if (x === arr[x]) {
      return x;
    }
    return (arr[x] = getParent(arr[x]));
  }

  function findParent(x, y) {
    x = getParent(x);
    y = getParent(y);

    if (x === y) return true;

    return false;
  }

  function Union(x, y) {
    x = getParent(x);
    y = getParent(y);

    if (x < y) arr[y] = x;
    else arr[x] = y;
  }

  costs.sort((a, b) => a[2] - b[2]);

  for (let i = 0; i < n; ++i) {
    arr[i] = i;
  }

  let sum = 0;

  costs.forEach((item) => {
    const [x, y, cost] = item;

    if (!findParent(x, y)) {
      sum += cost;
      Union(x, y);
    }
  });

  return sum;
}
