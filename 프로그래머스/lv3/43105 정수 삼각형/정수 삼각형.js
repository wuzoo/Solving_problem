function solution(triangle) {
  var answer = 0;

  const dp = Array.from(Array(triangle.length + 1), () =>
    Array(triangle.length + 1).fill(0)
  );

  for (let i = 1; i <= triangle.length; ++i) {
    for (let j = 1; j <= triangle[i - 1].length; ++j) {
      dp[i][j] = Math.max(
        dp[i - 1][j] + triangle[i - 1][j - 1],
        dp[i - 1][j - 1] + triangle[i - 1][j - 1]
      );
    }
  }

  answer = Math.max(...dp[triangle.length]);

  return answer;
}
