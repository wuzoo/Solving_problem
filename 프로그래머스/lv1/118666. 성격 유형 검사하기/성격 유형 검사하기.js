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

/** 다시 풀기 코드
 * function solution(survey, choices) {
    var answer = '';
    
    const index = ["RT", "CF", "JM", "AN"];
    const score = new Map();
    index.forEach(str => str.split("").forEach(char => score.set(char, 0)));
    
    survey.forEach((str, idx) => {
        const [left, right] = str.split("");
        
        score.set(choices[idx] < 4 ? left : right, score.get(choices[idx] < 4 ? left : right) + Math.abs((4 - choices[idx])));
    })
    
    index.forEach(str => {
        const [left, right] = str.split("");
        answer += score.get(left) >= score.get(right) ? left : right;
    })
    
    return answer;
}
 */
