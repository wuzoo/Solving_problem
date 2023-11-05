function solution(ingredient) {
  var answer = 0;

  const len = ingredient.length;

  let st = [];
  let idx = 0;
  for (let i = 0; i < len; ++i) {
    st.push(ingredient[i]);
    if (st.length >= 4) {
      if (
        st[st.length - 1] === 1 &&
        st[st.length - 2] === 3 &&
        st[st.length - 3] === 2 &&
        st[st.length - 4] === 1
      ) {
        for (let i = 0; i < 4; ++i) {
          st.pop();
        }
        answer++;
      }
    }
  }

  return answer;
}
