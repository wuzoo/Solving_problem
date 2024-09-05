function solution(babbling) {
  var answer = 0;

  function allchange(str) {
    return str
      .replace(/aya/g, (v) => "A")
      .replace(/ye/g, (v) => "B")
      .replace(/woo/g, (v) => "C")
      .replace(/ma/g, (v) => "D");
  }

  // aya를 A, ye를 B, woo를 C, ma를 D 로 바꾸었을 때
  // 같은 알파벳이 연속으로 나오면 안됨.
  // ABCD로만 이루어져 있어야함
  // 위 두개 조건 만족 시 발음할 수 있는 단어.

  babbling.forEach((str) => {
    let tmp = allchange(str);
    if (/[^ABCD]/.test(tmp)) return;
    if (/(A{2,}|B{2,}|C{2,}|D{2,})/.test(tmp)) return;

    answer++;
  });

  return answer;
}
