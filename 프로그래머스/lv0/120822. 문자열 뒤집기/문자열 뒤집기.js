function solution(my_string) {
  var answer = "";

  answer = my_string.split("").reverse().join("");
  // answer = [...my_string].reverse().join("");

  return answer;
}
