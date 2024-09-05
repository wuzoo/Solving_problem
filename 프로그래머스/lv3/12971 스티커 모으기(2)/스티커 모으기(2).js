function solution(sticker) {
  const n = sticker.length;
  const dp1 = new Array(n).fill(0);
  const dp2 = new Array(n).fill(0);

  const exceptFirst = sticker.length > 1 ? sticker.slice(1) : [sticker[0]];
  const exceptLast =
    sticker.length > 1 ? sticker.slice(0, sticker.length - 1) : [sticker[0]];

  exceptFirst.forEach((item, idx) => (dp1[idx] = item));
  exceptLast.forEach((item, idx) => (dp2[idx] = item));

  dp1[0] = exceptFirst[0];
  dp2[0] = exceptLast[0];
  dp1[1] = Math.max(exceptFirst[0], exceptFirst[1]);
  dp2[1] = Math.max(exceptLast[0], exceptLast[1]);

  for (let i = 2; i < sticker.length - 1; ++i) {
    dp1[i] = Math.max(dp1[i] + dp1[i - 2], dp1[i - 1]);
    dp1[i] = Math.max(dp1[i - 1], dp1[i]);
    dp2[i] = Math.max(dp2[i] + dp2[i - 2], dp2[i - 1]);
    dp2[i] = Math.max(dp2[i - 1], dp2[i]);
  }

  if (n === 1) return Math.max(dp1[0], dp2[0]);

  return Math.max(dp1[n - 2], dp2[n - 2]);
}
