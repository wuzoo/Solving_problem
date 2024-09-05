function solution(s) {
  let stack = [];
  s.split(" ").map((item) => {
    if (item === "Z") stack.pop();
    else stack.push(item);
  });

  return stack.reduce((acc, cur) => acc + +cur, 0);
}
