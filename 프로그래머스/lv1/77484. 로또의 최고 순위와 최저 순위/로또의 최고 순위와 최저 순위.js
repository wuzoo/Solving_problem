function solution(lottos, win_nums) {
  var answer = [];

  let map = { 6: 1, 5: 2, 4: 3, 3: 4, 2: 5, default: 6 }; // 일치 개수 : 등수
  let zeronum = lottos.filter((v) => v === 0).length; // 0 개수
  let correctnum = win_nums.filter((v) => lottos.includes(v)).length; // 일치 개수

  answer.push(map[correctnum + zeronum > 1 ? correctnum + zeronum : "default"]);
  answer.push(map[correctnum > 1 ? correctnum : "default"]);

  return answer;
}
