function solution(s) {
  let exps = [
    /zero/g,
    /one/g,
    /two/g,
    /three/g,
    /four/g,
    /five/g,
    /six/g,
    /seven/g,
    /eight/g,
    /nine/g,
  ];

  let str = s;
  exps.forEach((exp, index) => {
    if (exp.test(str)) {
      str = str.replace(exp, (v) => index.toString());
    }
  });

  return +str;
}
