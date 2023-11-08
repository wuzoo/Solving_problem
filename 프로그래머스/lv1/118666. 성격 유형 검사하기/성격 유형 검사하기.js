function solution(survey, choices) {
  var answer = "";

  let map = {};
  const types = ["RT", "CF", "JM", "AN"];

  survey.forEach((item) => {
    item.split("").forEach((v) => (map[v] = 0));
  });

  choices.forEach((score, index) => {
    const [disagree, agree] = survey[index];

    map[score > 4 ? agree : disagree] += Math.abs(score - 4);
  });

  types.forEach(([a, b]) => (answer += map[a] < map[b] ? b : a));

  return answer;
}
