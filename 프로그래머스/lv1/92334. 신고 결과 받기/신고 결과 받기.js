function solution(id_list, report, k) {
  let map = {};
  let result = {};

  id_list.forEach((item) => {
    let users = [];
    map[item] = users;
    result[item] = 0;
  });

  report.forEach((item) => {
    let user = item.split(" ")[0];
    let who = item.split(" ")[1];

    if (map[who].includes(user)) return;
    map[who].push(user);
  });
  for (let entries of Object.entries(map)) {
    if (entries[1].length >= k) {
      entries[1].map((item, idx) => result[item]++);
    }
  }
  return id_list.map((item) => result[item]);
}
