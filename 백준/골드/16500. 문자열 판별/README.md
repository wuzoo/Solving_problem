# [Gold 5] 문자열 판별 - 16500

<a href="https://www.acmicpc.net/problem/16500">- 문제링크</a>

## 성능 요약

메모리: 2028KB, 시간: 0ms

## 구분

- 다이나믹 프로그래밍
    
## 채점 결과

정확성: 100.0
합계: 100.0 / 100.0

## 문제 설명

알파벳 소문자로 이루어진 문자열 S와 단어 목록 A가 주어졌을 때, S를 A에 포함된 문자열을 한 개 이상 공백없이 붙여서 만들 수 있는지 없는지 구하는 프로그램을 작성하시오. A에 포함된 단어를 여러 번 사용할 수 있다.

## 입력

첫째 줄에 길이가 100이하인 문자열 S가 주어진다. 둘째 줄에는 A에 포함된 문자열의 개수 N(1 ≤ N ≤ 100)이 주어진다. 셋째 줄부터 N개의 줄에는 A에 포함된 단어가 한 줄에 하나씩 주어진다. A에 포함된 문자열은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.

## 출력

A에 포함된 문자열로 S를 만들 수 있으면 1, 없으면 0을 출력한다.