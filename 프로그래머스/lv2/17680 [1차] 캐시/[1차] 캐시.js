function solution(cacheSize, cities) {
  var answer = 0;

  if (cacheSize === 0) return cities.length * 5;

  const cachelist = [];
  cities = cities.map((str) => str.toUpperCase());

  cities.forEach((str) => {
    if (cachelist.includes(str)) {
      const originIdx = cachelist.indexOf(str);
      cachelist.splice(originIdx, 1);
      cachelist.push(str);
      answer++;
    } else {
      if (cachelist.length === cacheSize) cachelist.shift();
      cachelist.push(str);
      answer += 5;
    }
  });

  return answer;
}
