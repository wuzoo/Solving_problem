function solution(arr) {
  var answer = [];

  function quad(x, y, n) {
    if (n === 1) {
      return;
    }
    const current = arr[x][y];
    let canMake = true;
    for (let i = x; i < x + n; ++i) {
      for (let j = y; j < y + n; ++j) {
        if (arr[i][j] !== current) {
          canMake = false;
          break;
        }
      }
    }
    if (!canMake) {
      quad(x, y, n / 2);
      quad(x + n / 2, y, n / 2);
      quad(x, y + n / 2, n / 2);
      quad(x + n / 2, y + n / 2, n / 2);
    } else {
      for (let i = x; i < x + n; ++i) {
        for (let j = y; j < y + n; ++j) {
          if (i === x && j === y) continue;
          arr[i][j] = -1;
        }
      }
    }
  }

  quad(0, 0, arr.length);

  const zero = arr.reduce(
    (arr, cur) => arr + cur.filter((item) => item === 0).length,
    0
  );
  const one = arr.reduce(
    (arr, cur) => arr + cur.filter((item) => item === 1).length,
    0
  );

  answer = [zero, one];

  return answer;
}
