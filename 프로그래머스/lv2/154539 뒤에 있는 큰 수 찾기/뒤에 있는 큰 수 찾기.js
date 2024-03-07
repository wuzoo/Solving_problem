function solution(numbers) {
  var answer = [-1];

  const st = [];
  st.push(numbers[numbers.length - 1]);

  for (let i = numbers.length - 2; i >= 0; --i) {
    let num = -1;

    while (st.length) {
      if (st[0] > numbers[i]) {
        num = st[0];
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
