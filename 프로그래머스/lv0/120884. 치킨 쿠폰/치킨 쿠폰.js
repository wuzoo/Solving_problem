function getCoupon(chicken) {
  let coupon = chicken;

  let survice = 0;
  while (coupon >= 10) {
    survice += Math.floor(coupon / 10);
    coupon = Math.floor(coupon / 10) + (coupon % 10);
  }

  return survice;
}
function solution(chicken) {
  var answer = 0;

  return getCoupon(chicken);
}
