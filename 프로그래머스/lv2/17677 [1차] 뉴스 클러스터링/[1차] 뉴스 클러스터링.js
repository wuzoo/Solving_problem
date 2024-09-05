function slicedString(str) {
  const res = [];
  const regexp = /[A-Za-z]{2}/;
  for (let i = 0; i <= str.length - 2; ++i) {
    const s = str.slice(i, i + 2);
    if (!regexp.test(s)) continue;

    res.push(s.toUpperCase());
  }
  return res;
}

function solution(str1, str2) {
  const arr1 = slicedString(str1);
  const arr2 = slicedString(str2);

  let inter = 0;
  let union = 0;

  const totalArr = [...new Set(arr1.concat(arr2))];

  totalArr.forEach((str) => {
    const arr1Cnt = arr1.filter((item) => item === str).length;
    const arr2Cnt = arr2.filter((item) => item === str).length;

    inter += Math.min(arr1Cnt, arr2Cnt);
    union += Math.max(arr1Cnt, arr2Cnt);
  });

  return union === 0 ? 65536 : Math.floor((inter / union) * 65536);
}
