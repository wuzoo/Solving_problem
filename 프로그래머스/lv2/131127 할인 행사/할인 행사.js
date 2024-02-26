function solution(want, number, discount) {
  var answer = 0;

  const map = new Map();
  want.forEach((item, index) => {
    map.set(item, number[index]);
  });

  for (let i = 0; i <= discount.length - 10; ++i) {
    const str = discount.slice(i, i + 10);

    const tmp = {};
    str.forEach((item) => {
      if (tmp[item]) {
        tmp[item]++;
      } else {
        tmp[item] = 1;
      }
    });
    let correct = true;
    for (let [key, value] of map) {
      if (tmp[key] !== map.get(key)) {
        correct = false;
        break;
      }
    }
    if (correct) answer++;
  }
  return answer;
}
