function solution(my_string) {
  let arr = my_string.split(" ");
  let sum = 0;
  let st = [];
  arr.map((item) => {
    if (item.match(/\d+/g)) {
      if (st.length) {
        sum = st[0] === "+" ? sum + +item : sum - +item;
        st.pop();
      } else {
        sum += +item;
      }
    } else {
      st.push(item);
    }
  });

  return sum;
}
