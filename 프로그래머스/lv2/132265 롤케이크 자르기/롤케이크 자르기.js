function solution(topping) {
  let cnt = 0;

  const cnts = new Array(topping.length).fill(0); // 각 인덱스에서 잘랐을 시의 토핑 수 배열
  const oppCnts = new Array(topping.length).fill(0); // 뒤에서부터 인덱스에서 잘랐을 시의 토핑 수 배열

  const stVisited = new Array(10001).fill(0);
  const oppStVisited = new Array(10001).fill(0);

  let st = [];
  let oppSt = [];
  topping.forEach((item, index) => {
    if (stVisited[item] === 0) {
      stVisited[item] = 1;
      st.push(item);
    }
    cnts[index] = st.length;
  });
  for (let i = topping.length - 1; i >= 0; --i) {
    oppCnts[i] = oppSt.length;
    if (oppStVisited[topping[i]] === 0) {
      oppStVisited[topping[i]] = 1;
      oppSt.push(topping[i]);
    }
  }

  cnts.forEach((item, index) => {
    if (cnts[index] === oppCnts[index]) {
      cnt++;
    }
  });

  return cnt;
}
