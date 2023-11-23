function solution(participant, completion) {
  var answer = "";

  let part = {};

  participant.map((item) => {
    part[item] = (part[item] || 0) + 1;
  });
  completion.map((item) => {
    part[item]--;
  });
  for (let key in part) {
    if (part[key] === 1) answer += key;
  }

  return answer;
}
