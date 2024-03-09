// 1
function solution(prices) {
  const ans = new Array(prices.length).fill(0);

  const st = [];
  prices.forEach((item, index) => {
    while (true) {
      const idx = st[st.length - 1];
      if (prices[idx] > item) {
        st.pop();
        ans[idx] = index - idx;
        continue;
      }
      st.push(index);
      break;
    }
  });
  if (st.length) {
    for (let i = 0; i < st.length; ++i) {
      ans[st[i]] = prices.length - 1 - st[i];
    }
  }

  return ans;
}

// 2
function solution(prices) {
  var answer = [];

  for (let i = 0; i < prices.length; ++i) {
    const price = prices[i];

    let cnt = 0;
    for (let j = i + 1; j < prices.length; ++j) {
      cnt++;
      if (prices[j] < price) break;
    }
    answer.push(cnt);
  }

  return answer;
}
