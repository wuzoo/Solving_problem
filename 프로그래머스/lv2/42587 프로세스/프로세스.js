function solution(priorities, location) {
  var answer = 1;

  const idxs = priorities.map((_, i) => i);

  while (true) {
    if (priorities[0] === Math.max(...priorities)) {
      if (idxs[0] === location) {
        break;
      }
      priorities.splice(0, 1);
      idxs.splice(0, 1);
      answer++;
    } else {
      const value = priorities[0];
      const idx = idxs[0];

      priorities.splice(0, 1);
      idxs.splice(0, 1);

      priorities.push(value);
      idxs.push(idx);
    }
  }

  return answer;
}
