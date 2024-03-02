function solution(phone_book) {
  const map = new Map();

  phone_book.forEach((item) => {
    for (let i = 0; i <= item.length; ++i) {
      if (map.has(item.slice(0, i))) {
        map.set(item.slice(0, i), map.get(item.slice(0, i)) + 1);
      } else {
        map.set(item.slice(0, i), 1);
      }
    }
  });

  let answer = true;

  phone_book.forEach((item) => {
    if (map.get(item) > 1) {
      answer = false;
    }
  });

  return answer;
}
