function solution(elements) {
  var answer = 0;

  const lens = [];
  for (let i = 1; i <= elements.length; ++i) {
    // 길이
    for (let j = 0; j < elements.length; ++j) {
      // 출발 인덱스
      let sum = 0;
      for (let k = j; k < i + j; ++k) {
        sum += elements[circleIdx(k, elements.length)];
      }
      lens.push(sum);
      sum = 0;
    }
  }

  return [...new Set(lens)].length;
}

function circleIdx(idx, len) {
  if (idx > len - 1) {
    return idx % len;
  }
  return idx;
}
