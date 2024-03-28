function solution(str1, str2) {
  const arr1 = [];
  const arr2 = [];

  const regexp = /[a-zA-Z][a-zA-Z]/;

  for (let i = 0; i < str1.length - 1; ++i) {
    const tmp = str1.toLowerCase().slice(i, i + 2);

    if (!regexp.test(tmp)) continue;
    arr1.push(tmp);
  }
  for (let i = 0; i < str2.length - 1; ++i) {
    const tmp = str2.toLowerCase().slice(i, i + 2);

    if (!regexp.test(tmp)) continue;
    arr2.push(tmp);
  }

  let inter = 0;
  let union = 0;

  const unionArr = [...new Set(arr1.concat(arr2))];

  unionArr.forEach((e) => {
    const has1 = arr1.filter((item) => item === e).length;
    const has2 = arr2.filter((item) => item === e).length;

    inter += Math.min(has1, has2);
    union += Math.max(has1, has2);
  });

  return inter === 0 && union === 0
    ? 65536
    : Math.floor((inter / union) * 65536);
}
