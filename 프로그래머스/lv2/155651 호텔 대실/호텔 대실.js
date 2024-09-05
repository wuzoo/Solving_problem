function solution(book_time) {
  let answer = 0;
  let convertTime = [];
  let roomEndTime = [];

  let sortedBookTime = book_time.sort();

  for (let i = 0; i < sortedBookTime.length; i++) {
    let start = sortedBookTime[i][0].split(":");
    let end = sortedBookTime[i][1].split(":");

    let startTime = Number(start[0]) * 60 + Number(start[1]);
    let endTime = Number(end[0]) * 60 + (Number(end[1]) + 10);

    convertTime.push([startTime, endTime]);
  }

  convertTime.forEach(([start, end]) => {
    if (roomEndTime.length === 0) ++answer;
    else if (roomEndTime.at(-1) <= start) {
      roomEndTime.pop();
    } else {
      ++answer;
    }
    roomEndTime.push(end);
    roomEndTime.sort((a, b) => b - a);
  });

  return answer;
}
