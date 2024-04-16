function solution(numbers) {
  const answer = [-1];

  const st = [numbers.at(-1)];
  for (let i = numbers.length - 2; i >= 0; --i) {
    let num = -1;
    while (st.length) {
      if (st.at(0) > numbers[i]) {
        num = st.at(0);
        break;
      } else {
        st.shift();
      }
    }
    answer.push(num);
    st.unshift(numbers[i]);
  }

  return answer.reverse();
}
