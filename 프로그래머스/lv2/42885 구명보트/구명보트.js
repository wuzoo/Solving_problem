function solution(people, limit) {
  people.sort((a, b) => a - b);

  let sum = 0;
  let cnt = 0;
  let left = 0;
  let right = people.length - 1;

  while (left <= right) {
    if (people[left] + people[right] > limit) {
      right--;
    } else {
      left++;
      right--;
    }
    cnt++;
  }

  return cnt;
}
