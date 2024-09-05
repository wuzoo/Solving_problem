function solution(expression) {
  let priority = [];
  const signs = ["+", "-", "*"];
  const visited = new Array(3).fill(0);

  function DFS(str, k) {
    if (k === 3) {
      priority.push(str);
      return;
    }
    for (let i = 0; i < 3; ++i) {
      if (!visited[i]) {
        visited[i] = 1;
        DFS(str + signs[i], k + 1);
        visited[i] = 0;
      }
    }
  }

  DFS("", 0);

  function calc(a, b, op) {
    a = parseInt(a);
    b = parseInt(b);
    switch (op) {
      case "+":
        return a + b;
      case "-":
        return a - b;
      case "*":
        return a * b;
    }
  }

  expression = expression.match(/\d+|[\-\+\*]/g);

  let max = 0;
  priority.forEach((signs) => {
    let current = [...expression];

    signs.split("").forEach((sign) => {
      let idx = 0;

      while (true) {
        idx = current.indexOf(sign);

        if (idx === -1) break;

        let sum = calc(current[idx - 1], current[idx + 1], sign);

        current.splice(idx - 1, 3, sum);
      }
    });
    max = Math.max(max, Math.abs(current));
  });

  return max;
}
