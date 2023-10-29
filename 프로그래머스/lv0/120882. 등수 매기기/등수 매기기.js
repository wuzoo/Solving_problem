function solution(score) {
  var answer = [];

  let gradearr = new Array(score.length).fill(0);

  let tmparr = [];
  score.map((item) => tmparr.push((item[0] + item[1]) / 2));

  tmparr.map((item, index) => {
    // item : 현재 인덱스 점수
    let biggerthanmeCount = 0;
    tmparr.forEach((score) => {
      // score : 탐색 점수
      if (score > item) {
        biggerthanmeCount++;
      }
    });
    gradearr[index] = 1 + biggerthanmeCount;
  });

  return gradearr;
}
