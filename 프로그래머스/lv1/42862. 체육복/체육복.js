function solution(n, lost, reserve) {
  let visited = new Array(n + 1).fill(0);
  let students = new Array(n + 1).fill(1);

  reserve.forEach((num) => (visited[num] = 1)); // 여벌 가져온 애들 1로 처리
  lost.forEach((num) => {
    if (visited[num] !== 1) {
      // 잃어버린 애 중 여벌 없는 애들은
      students[num] = 0; // 일단 옷 못입음
    } else if (visited[num] === 1) {
      // 잃어버린 애들 중 여벌 가져온 애들은
      visited[num] = 0; // 여벌 없음 처리 + 이제 못빌려줌
    }
  });

  lost
    .sort((a, b) => a - b)
    .forEach((num) => {
      if (students[num] === 1) return;

      let canborrow = [];
      if (num - 1 >= 1) canborrow.push(num - 1);
      if (num + 1 <= n) canborrow.push(num + 1);

      let go = true;
      canborrow.forEach((item) => {
        if (visited[item] === 1 && go) {
          visited[item] = 0;
          students[num] = 1;
          go = false;
        }
      });
    });

  return students.filter((v) => v === 1).length - 1;
}
