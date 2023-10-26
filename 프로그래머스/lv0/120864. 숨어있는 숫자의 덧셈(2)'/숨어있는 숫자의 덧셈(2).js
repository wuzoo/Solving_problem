// function solution(my_string) {
//   let answer = 0;
//   let arr = [];
//   let tmparr = "";
//   my_string.split("").map((item, index) => {
//     if (+item >= 0 && +item <= 9) {
//       tmparr += item;
//     } else {
//       if (tmparr.length !== 0) {
//         arr.push(+tmparr);
//         tmparr = "";
//       }
//     }
//   });
//   if (tmparr.length !== 0) arr.push(+tmparr);

//   if (arr.length === 0) return 0;

//   arr.forEach((element) => (answer += element));
//   return answer;
// }
function solution(my_string) {
  return my_string.split(/[A3-z]/g).reduce((acc, cur) => acc + +cur, 0);
}
