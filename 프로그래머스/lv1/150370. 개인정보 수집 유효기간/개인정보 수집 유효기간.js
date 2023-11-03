function solution(today, terms, privacies) {
  var answer = [];

  let [todayyear, todaymonth, todayday] = today.split(".").map((item) => +item);

  let map = {};

  terms.forEach((item) => {
    const [info, months] = item.split(" ");
    map[info] = months;
  });

  privacies.forEach((privacy, index) => {
    const [startday, info] = privacy.split(" ");
    let [yy, mm, dd] = startday.split(".").map((item) => +item);

    let monthrange = +map[info];

    mm += monthrange; // 1 ~ 12, 13 ~ 24,
    let unit = 0;
    while (mm > 12) {
      mm -= 12;
      unit++;
    }
    yy += unit;

    if (dd === 1) {
      dd = 28;
      if (mm === 1) {
        mm = 12;
        yy--;
      } else {
        mm--;
      }
    } else {
      dd--;
    }

    if (yy > todayyear) return;
    if (yy === todayyear) {
      if (mm > todaymonth) return;
      if (mm === todaymonth) {
        if (dd >= todayday) return;
      }
    }
    answer.push(index + 1);
  });

  return answer;
}
