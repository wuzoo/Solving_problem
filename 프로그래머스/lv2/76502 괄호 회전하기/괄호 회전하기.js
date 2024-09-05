function solution(s) {
  let iter = s.length;
  let cnt = 0;
  while (iter--) {
    const st = [];
    for (let i = 0; i < s.length; ++i) {
      if (i !== 0) {
        if (st[st.length - 1] === "(" && s[i] === ")") {
          st.pop();
          continue;
        } else if (st[st.length - 1] === "[" && s[i] === "]") {
          st.pop();
          continue;
        } else if (st[st.length - 1] === "{" && s[i] === "}") {
          st.pop();
          continue;
        }
      }
      st.push(s[i]);
    }
    if (st.length === 0) {
      cnt++;
    }
    s = s.slice(1) + s.slice(0, 1);
  }

  return cnt;
}
