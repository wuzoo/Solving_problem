# [Gold 4] 스도쿠 - 2239

<a href="https://www.acmicpc.net/problem/2239">- 문제링크</a>

## 성능 요약

메모리: 2020KB, 시간: 540ms

## 구분

- 수학
- 브루트포스 알고리즘
- 조합론
- 백트래킹
    
## 채점 결과

정확성: 100.0
합계: 100.0 / 100.0

## 문제 설명

스도쿠는 매우 간단한 숫자 퍼즐이다. 9×9 크기의 보드가 있을 때, 각 행과 각 열, 그리고 9개의 3×3 크기의 보드에 1부터 9까지의 숫자가 중복 없이 나타나도록 보드를 채우면 된다. 예를 들어 다음을 보자.

![](https://velog.velcdn.com/images/wuzoo/post/c89ec82a-1e02-45f5-aad0-f25b51ec3b3a/image.png)

위 그림은 참 잘도 스도쿠 퍼즐을 푼 경우이다. 각 행에 1부터 9까지의 숫자가 중복 없이 나오고, 각 열에 1부터 9까지의 숫자가 중복 없이 나오고, 각 3×3짜리 사각형(9개이며, 위에서 색깔로 표시되었다)에 1부터 9까지의 숫자가 중복 없이 나오기 때문이다.

하다 만 스도쿠 퍼즐이 주어졌을 때, 마저 끝내는 프로그램을 작성하시오.

## 입력

9개의 줄에 9개의 숫자로 보드가 입력된다. 아직 숫자가 채워지지 않은 칸에는 0이 주어진다.

## 출력

9개의 줄에 9개의 숫자로 답을 출력한다. 답이 여러 개 있다면 그 중 사전식으로 앞서는 것을 출력한다. 즉, 81자리의 수가 제일 작은 경우를 출력한다.