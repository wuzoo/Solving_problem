function getTime(time) {
  const [h, m] = time.split(":");

  return +h * 60 + +m;
}

function solution(fees, records) {
  const answer = [];

  const timeMap = new Map();
  const feeMap = new Map();

  records.forEach((str) => {
    const id = str.split(" ")[1];
    timeMap.set(id, {});
    feeMap.set(id, 0);
  });

  records.forEach((str) => {
    const [time, id, flag] = str.split(" ");
    if (flag === "IN") {
      timeMap.get(id).start = time;
    } else if (flag === "OUT") {
      timeMap.get(id).end = time;
      const fee = getTime(timeMap.get(id).end) - getTime(timeMap.get(id).start);
      feeMap.set(id, feeMap.get(id) + fee);
      timeMap.set(id, {});
    }
  });

  for (let [key, value] of timeMap) {
    const { start, end } = value;
    const lastTime = getTime("23:59");
    if (start !== undefined && !end) {
      feeMap.set(key, feeMap.get(key) + lastTime - getTime(start));
    }
  }
  for (let [key, value] of feeMap) {
    let fee = fees[1];
    if (value > fees[0]) {
      fee += Math.ceil((value - fees[0]) / fees[2]) * fees[3];
    }
    answer.push([key, fee]);
  }

  return answer.sort((a, b) => +a[0] - +b[0]).map((item) => item[1]);
}
