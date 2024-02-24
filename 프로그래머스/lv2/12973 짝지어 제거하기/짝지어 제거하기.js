function solution(s) {
  var answer = -1;

  const st = [];

  for (let i = 0; i < s.length; ++i) {
    if (i !== 0) {
      if (st[st.length - 1] === s[i]) {
        st.pop();
        continue;
      }
    }
    st.push(s[i]);
  }

  return st.length === 0 ? 1 : 0;
}
