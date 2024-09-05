function solution(friends, gifts) {
  const dict = new Map();
  const digit = new Map(); // 선물 지수
  let answer = new Map();

  friends.forEach((name) => {
    dict.set(name, []);
    digit.set(name, 0);
    answer.set(name, 0);
  });

  gifts.forEach((str) => {
    const [sender, receiver] = str.split(" ");

    dict.get(sender).push(receiver);
    digit.set(sender, digit.get(sender) + 1);
    digit.set(receiver, digit.get(receiver) - 1);
  });

  for (let i = 0; i < friends.length; ++i) {
    for (let j = 0; j < friends.length; ++j) {
      const sendCnt = dict
        .get(friends[i])
        .filter((name) => name === friends[j]).length;
      const receiveCnt = dict
        .get(friends[j])
        .filter((name) => name === friends[i]).length;

      if (sendCnt > receiveCnt)
        answer.set(friends[i], answer.get(friends[i]) + 1);
      else if (sendCnt === receiveCnt) {
        if (digit.get(friends[i]) > digit.get(friends[j])) {
          answer.set(friends[i], answer.get(friends[i]) + 1);
        }
      }
    }
  }
  let mx = 0;
  for (let [name, cnt] of answer) {
    mx = Math.max(mx, cnt);
  }

  return mx;
}
