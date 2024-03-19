function solution(n) {
  const st = [];

  while (n > 0) {
    if (n % 3 === 0) {
      st.push(4);
      n = Math.floor(n / 3) - 1;
    } else {
      st.push(n % 3);
      n = Math.floor(n / 3);
    }
  }

  return st.reverse().join("");
}
