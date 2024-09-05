function solution(record) {
  const answer = [];
  const userMap = new Map();

  record.forEach((str) => {
    const [flag, id, name] = str.split(" ");

    if (flag === "Enter" || flag === "Change") {
      userMap.set(id, name);
    }
  });

  record.forEach((str) => {
    const [flag, id, name] = str.split(" ");

    if (flag === "Enter") {
      answer.push(`${userMap.get(id)}님이 들어왔습니다.`);
    } else if (flag === "Leave") {
      answer.push(`${userMap.get(id)}님이 나갔습니다.`);
    }
  });

  return answer;
}
