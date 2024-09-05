function solution(id_list, report, k) {
  var answer = [];

  const reportCntMap = new Map();
  const reportNameMap = new Map();

  id_list.forEach((name) => {
    reportCntMap.set(name, 0);
    reportNameMap.set(name, []);
  });

  report.forEach((str) => {
    const [reporter, reported] = str.split(" ");
    if (!reportNameMap.get(reporter).includes(reported)) {
      reportNameMap.get(reporter).push(reported);
      reportCntMap.set(reported, reportCntMap.get(reported) + 1);
    }
  });

  id_list.forEach((name) => {
    const mailCnt = reportNameMap
      .get(name)
      .filter((item) => reportCntMap.get(item) >= k).length;
    answer.push(mailCnt);
  });
  return answer;
}
