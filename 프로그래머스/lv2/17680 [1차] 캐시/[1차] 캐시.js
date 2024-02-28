function solution(cacheSize, cities) {
  const list = [];
  let time = 0;

  if (cacheSize === 0) {
    return cities.length * 5;
  }

  cities.forEach((item) => {
    if (list.includes(item.toUpperCase())) {
      const idx = list.findIndex((city) => city === item.toUpperCase());
      list.splice(idx, 1);
      list.push(item.toUpperCase());
      time++;
    } else {
      if (list.length === cacheSize) {
        list.splice(0, 1);
      }
      list.push(item.toUpperCase());
      time += 5;
    }
  });

  return time;
}
