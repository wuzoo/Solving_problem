function solution(s) {
  const max = Math.max(...s.split(" "));
  const min = Math.min(...s.split(" "));

  return min + " " + max;
}
