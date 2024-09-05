function solution(jobs) {
  const heap = [];

  let sum = 0;
  let index = 0;
  let currentTime = 0;
  jobs.sort((a, b) => a[0] - b[0]);

  while (index < jobs.length || heap.length > 0) {
    if (index < jobs.length && currentTime >= jobs[index][0]) {
      heap.push(jobs[index]);
      index += 1;

      heap.sort((a, b) => a[1] - b[1]);
    } else if (!heap.length) {
      currentTime = jobs[index][0];
    } else {
      const [start, end] = heap.shift();
      sum += currentTime + end - start;
      currentTime += end;
    }
  }

  return Math.floor(sum / jobs.length);
}
