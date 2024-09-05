function solution(k, m, score) {
  var answer = 0;
  let scorearr = score.sort((a, b) => b - a);

  scorearr.map((item, index) => {
    if ((index + 1) % m === 0 && index !== 0) {
      answer += m * scorearr[index];
    }
  });

  return answer;
}
