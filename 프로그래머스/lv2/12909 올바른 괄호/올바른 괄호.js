function solution(s) {
  var answer = true;

  const st = [];

  s.split("").forEach((item) => {
    if (item === "(") {
      st.push(item);
    } else if (item === ")") {
      if (st[st.length - 1] === "(") {
        st.pop();
      } else {
        st.push(item);
      }
    }
  });

  if (st.length !== 0) {
    return false;
  }

  return true;
}
