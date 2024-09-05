// function solution(array, n) {
//   var answer = 0;

//   let maxclose = 101;
//   array.map((item) => {
//     if (Math.abs(item - n) === maxclose) {
//       if (item < n) {
//         answer = item;
//       }
//     }
//     if (Math.abs(item - n) < maxclose) {
//       maxclose = Math.abs(item - n);
//       answer = item;
//     }
//   });

//   return answer;
// }
function solution(array, n) {
  return array
    .sort()
    .reduce((a, c) =>
      Math.abs(a - n) < Math.abs(c - n)
        ? a
        : Math.abs(a - n) === Math.abs(c - n)
        ? a
        : c
    );
}
