function solution(arr1, arr2) {
  const len1 = arr1.length;
  const len2 = arr2[0].length;

  const answer = Array.from(Array(len1), () => Array(len2).fill(0));

  arr1.forEach((item, index) => {
    for (let i = 0; i < arr2[0].length; ++i) {
      let sum = 0;
      for (let j = 0; j < item.length; ++j) {
        sum += item[j] * arr2[j][i];
      }
      answer[index][i] = sum;
    }
  });

  return answer;
}
