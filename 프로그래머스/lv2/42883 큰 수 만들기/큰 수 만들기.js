function solution(number, k) {
  const st = [];

  number.split("").forEach((item) => {
    while (st.length && k > 0) {
      if (st.at(-1) < item) {
        st.pop();
        k--;
      } else break;
    }
    st.push(item);
  });

  if (k !== 0) {
    while (k > 0) {
      st.pop();
      k--;
    }
  }
  return st.join("");
}
