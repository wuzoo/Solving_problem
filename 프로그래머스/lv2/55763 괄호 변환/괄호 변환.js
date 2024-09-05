function solution(p) {
  return solve(p);
}

function solve(string) {
  if (string === "") return "";

  const [u, v] = balancedStr(string);

  if (isRight(u)) {
    return u + solve(v);
  } else {
    let tmp = "(" + solve(v) + ")";
    let converted = "";
    u.slice(1, u.length - 1)
      .split("")
      .forEach((c) => {
        if (c === ")") converted += "(";
        else converted += ")";
      });
    return tmp + converted;
  }
}

function balancedStr(str) {
  let leftCnt = 0;
  let rightCnt = 0;
  const stack = [];
  for (let i = 0; i < str.length; ++i) {
    if (str[i] === "(") {
      stack.push("(");
      leftCnt++;
    } else if (str[i] === ")") {
      stack.push(")");
      rightCnt++;
    }

    if (leftCnt === rightCnt) break;
  }
  return [stack.join(""), str.slice(stack.length)];
}
function isRight(str) {
  const st = [];
  for (let i = 0; i < str.length; ++i) {
    if (str[i] === ")") {
      if (st.length === 0) return false;
      else if (st.at(-1) === "(") {
        st.pop();
      } else {
        return false;
      }
    } else {
      st.push(str[i]);
    }
  }
  return true;
}
