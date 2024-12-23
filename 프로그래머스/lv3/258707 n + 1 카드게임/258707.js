function solution(coin, cards) {
  const n = cards.length;

  const origin = new Set();
  const get = new Set();

  for (let i = 0; i < n / 3; ++i) {
    origin.add(cards[i]);
  }

  function match(s1, s2) {
    for (const v of s1) {
      if (s2.has(n + 1 - v)) {
        s1.delete(v);
        s2.delete(n + 1 - v);
        return true;
      }
    }
    return false;
  }

  let round = 1;
  for (let i = n / 3; i < cards.length; i += 2) {
    const num1 = cards[i];
    const num2 = cards[i + 1];

    get.add(num1);
    get.add(num2);

    let canGo = false;

    if (match(origin, origin)) {
      round++;
      continue;
    }
    if (coin >= 1 && match(origin, get)) {
      coin--;
      canGo = true;
    } else if (coin >= 2 && match(get, get)) {
      coin -= 2;
      canGo = true;
    }

    if (!canGo) break;

    round++;
  }

  return round;
}
