function solution(spell, dic) {
  var answer = 2;

  let tmp = spell.sort().join("");

  dic.map((item) => {
    let dicname = item.split("").sort().join("");

    if (dicname === tmp) {
      answer = 1;
      return;
    }
  });

  return answer;
}
