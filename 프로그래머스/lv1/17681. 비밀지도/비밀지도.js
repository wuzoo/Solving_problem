function solution(n, arr1, arr2) {
  var answer = [];

  for (let i = 0; i < n; ++i) {
    let num1 = arr1[i];
    let num2 = arr2[i];

    let arr = new Array(n).fill(0);
    for (let i = n - 1; i >= 0; --i) {
      if (num1 >= Math.pow(2, i)) {
        num1 -= Math.pow(2, i);
        arr[n - i - 1] = 1;
      }
    }
    for (let i = n - 1; i >= 0; --i) {
      if (num2 >= Math.pow(2, i)) {
        num2 -= Math.pow(2, i);
        arr[n - i - 1] = 1;
      }
    }
    answer.push(arr.map((item) => (item === 0 ? " " : "#")).join(""));
  }

  return answer;
}
