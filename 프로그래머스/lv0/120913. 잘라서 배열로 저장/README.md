# [level 0] 잘라서 배열로 저장 - 120913

<a href="https://school.programmers.co.kr/learn/courses/30/lessons/120913">- 문제링크</a>

## 성능 요약

메모리: 33.5MB, 시간: 0.6ms

## 구분

코딩테스트 연습 > 코딩테스트 입문

## 채점 결과

정확성: 100.0
합계: 100.0 / 100.0

## 문제 설명

문자열 my_str과 n이 매개변수로 주어질 때, my_str을 길이 n씩 잘라서 저장한 배열을 return하도록 solution 함수를 완성해주세요.

---

#### 제한사항

- 1 ≤ my_str의 길이 ≤ 100
- 1 ≤ n ≤ my_str의 길이
- my_str은 알파벳 소문자, 대문자, 숫자로 이루어져 있습니다.

#### 입출력 예

|     **my_str**     | **n** | **result**                   |
| :----------------: | :---: | ---------------------------- |
| "abc1Addfggg4556b" |   6   | ["abc1Ad", "dfggg4", "556b"] |
|    "abcdef123"     |   3   | ["abc", "def", "123"]        |

#### 입출력 예 설명

**입출력 예 #1**

- "abc1Addfggg4556b" 를 길이 6씩 잘라 배열에 저장한 ["abc1Ad", "dfggg4", "556b"]를 return해야 합니다.

**입출력 예 #2**

- "abcdef123" 를 길이 3씩 잘라 배열에 저장한 ["abc", "def", "123"]를 return해야 합니다.

> 출처 : 프로그래머스 코딩 테스트 연습, <https://school.programmers.co.kr/learn/challenges>
