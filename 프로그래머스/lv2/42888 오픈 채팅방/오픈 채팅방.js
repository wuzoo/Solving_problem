function solution(record) {
  var answer = [];

  const map = new Map();

  record.forEach((item) => {
    const command = item.split(" ")[0];
    const id = item.split(" ")[1];

    if (command === "Enter" || command === "Change") {
      const name = item.split(" ")[2];
      map.set(id, name);
    }
  });

  record.forEach((item) => {
    const command = item.split(" ")[0];
    const id = item.split(" ")[1];

    if (command === "Enter") {
      answer.push(map.get(id) + "님이 들어왔습니다.");
    } else if (command === "Leave") {
      answer.push(map.get(id) + "님이 나갔습니다.");
    }
  });

  return answer;
}
