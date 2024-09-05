function solution(clothes) {
  var answer = 1;

  const obj = {};
  clothes.forEach((item) => {
    if (!obj[item[1]]) {
      obj[item[1]] = 1;
    } else {
      obj[item[1]]++;
    }
  });

  for (let key in obj) {
    answer *= obj[key] + 1;
  }

  return answer - 1;
}
