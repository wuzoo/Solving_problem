function solution(cards1, cards2, goal) {
  var answer = "";

  let card1idx = 0;
  let card2idx = 0;
  goal.forEach((str) => {
    if (cards1[card1idx] === str) card1idx++;
    if (cards2[card2idx] === str) card2idx++;
  });
  let totallen = card1idx + card2idx;
  answer = totallen === goal.length ? "Yes" : "No";

  return answer;
}
