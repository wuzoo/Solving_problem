function solution(s) {
  let answer = "";

  s = s.toLowerCase();

  s.split(" ").forEach((string) => {
    const str = string.charAt(0).toUpperCase() + string.slice(1);

    answer += str;
    answer += " ";
  });

  return answer.slice(0, -1);
}
