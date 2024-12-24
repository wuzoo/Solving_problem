function solution(n, tops) {
  const MOD = 10007;

  const dp1 = new Array(n + 1).fill(0);
  const dp2 = new Array(n + 1).fill(0);

  dp1[1] = 1;
  dp2[1] = 2 + tops[0];
  for (let i = 2; i <= n; ++i) {
    dp1[i] = (dp1[i - 1] + dp2[i - 1]) % MOD;
    dp2[i] =
      (dp1[i - 1] * (tops[i - 1] + 1) + dp2[i - 1] * (tops[i - 1] + 2)) % MOD;
  }

  return (dp1[n] + dp2[n]) % MOD;
}
