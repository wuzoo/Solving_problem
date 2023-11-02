function solution(keymap, targets) {
  let answer = [];
  const map = {};

  keymap.forEach((key, idx) => {
    key
      .split("")
      .map(
        (letter, index) =>
          (map[letter] = map[letter] < index + 1 ? map[letter] : index + 1)
      );
  });

  targets.forEach((target, idx) => {
    answer.push(target.split("").reduce((acc, cur) => acc + map[cur], 0) || -1);
  });

  return answer;
}
