function zipString(s) {
  let result = [];

  for (let i = 0; i < s.length; ++i) {
    let cnt = 0;
    while (s[i] === s[i + 1]) {
      cnt++;
      i++;
    }
    if (cnt) {
      result.push(cnt + 1);
    }
    result.push(s[i]);
  }
  return result.join("");
}

function slicedString(s, n) {
  let res = [];
  for (let i = 0; i < s.length; i += n) {
    res.push(s.slice(i, i + n));
  }
  return res;
}

function solution(s) {
  var answer = 0;

  let minLen = 1001;
  for (let i = 1; i <= s.length; ++i) {
    minLen = Math.min(minLen, zipString(slicedString(s, i)).length);
  }

  return minLen;
}
