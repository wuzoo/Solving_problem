function solution(a, b, n) {
  let mine = n;

  let totalgive = 0;
  while (mine >= a) {
    let rest = mine % a;
    mine = Math.floor(mine / a);
    mine *= b;
    totalgive += mine;

    mine += rest;
  }

  return totalgive;
}
