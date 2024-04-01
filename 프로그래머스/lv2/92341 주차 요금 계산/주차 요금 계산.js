function solution(fees, records) {
  var answer = [];

  const [defaultTime, defaultFee, unitTime, unitFee] = fees;

  function calcTime(start, end) {
    const [hIn, mIn] = String(start)
      .split(":")
      .map((s) => +s);
    const [hOut, mOut] = String(end)
      .split(":")
      .map((s) => +s);

    return mOut - mIn + (hOut - hIn) * 60;
  }

  const startMap = new Map();
  const endMap = new Map();
  const feeMap = new Map();

  records.forEach((item) => {
    const [time, number, flag] = item.split(" ");

    if (flag === "IN") {
      startMap.set(number, time);
    } else if (flag === "OUT") {
      endMap.set(
        number,
        (endMap.get(number) ?? 0) + calcTime(startMap.get(number), time)
      );
      startMap.delete(number);
    }
  });

  for (let [key, value] of startMap) {
    const lastTime = "23:59";
    endMap.set(key, (endMap.get(key) ?? 0) + calcTime(value, lastTime));
  }

  for (let [key, value] of endMap) {
    if (value <= defaultTime) {
      answer.push([key, defaultFee]);
    } else {
      const fee =
        defaultFee + Math.ceil((value - defaultTime) / unitTime) * unitFee;
      answer.push([key, fee]);
    }
  }

  return answer.sort((a, b) => +a[0] - +b[0]).map((item) => item[1]);
}
