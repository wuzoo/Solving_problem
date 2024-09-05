function solution(name, yearning, photo) {
  var answer = [];

  photo.forEach((array) => {
    let sum = 0;
    array.forEach((nm, index) => {
      let idx = name.indexOf(nm);
      if (idx !== -1) {
        sum += yearning[idx];
      }
    });
    answer.push(sum);
  });

  return answer;
}
