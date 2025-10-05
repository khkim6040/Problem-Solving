# [level 4] 트리 트리오 중간값 - 68937 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/68937) 

### 성능 요약

메모리: 63.1 MB, 시간: 215.43 ms

### 구분

코딩테스트 연습 > 월간 코드 챌린지 시즌1

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2025년 10월 05일 13:49:07

### 문제 설명

<p>n개의 점으로 이루어진 트리가 있습니다. 이때, 트리 상에서 다음과 같은 것들을 정의합니다.</p>

<ul>
<li>어떤 두 점 사이의 거리는, 두 점을 잇는 경로 상 간선의 개수로 정의합니다.</li>
<li>임의의 3개의 점 a, b, c에 대한 함수 f(a, b, c)의 값을 a와 b 사이의 거리, b와 c 사이의 거리, c와 a 사이의 거리, 3개 값의 중간값으로 정의합니다.</li>
</ul>

<p>트리의 정점의 개수 n과 트리의 간선을 나타내는 2차원 정수 배열 edges가 매개변수로 주어집니다. 주어진 트리에서 임의의 3개의 점을 뽑아 만들 수 있는 모든 f값 중에서, 제일 큰 값을 구해 return 하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한 사항</h5>

<ul>
<li>n은 3 이상 250,000 이하입니다.</li>
<li>edges의 행의 개수는 n-1 입니다.

<ul>
<li>edges의 각 행은 [v1, v2] 2개의 정수로 이루어져 있으며, 이는 v1번 정점과 v2번 정점 사이에 간선이 있음을 의미합니다.</li>
<li>v1, v2는 각각 1 이상 n 이하입니다.</li>
<li>v1, v2는 다른 수입니다. </li>
<li>입력으로 주어지는 그래프는 항상 트리입니다.</li>
</ul></li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>n</th>
<th>edges</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>4</td>
<td><code>[[1,2],[2,3],[3,4]]</code></td>
<td>2</td>
</tr>
<tr>
<td>5</td>
<td><code>[[1,5],[2,5],[3,5],[4,5]]</code></td>
<td>2</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<ul>
<li>다음 그림은 입력으로 주어진 트리를 나타낸 것입니다.</li>
</ul>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/29fda5a8-3a49-4696-a9d7-3f9efff72a46/ex1.png" title="" alt="ex1.png"></p>

<ul>
<li>다음 표는 주어진 트리에서 나올 수 있는 모든 f값의 경우를 나열한 것입니다. (단, a, b, c의 순서만 다른 경우는 f값이 동일하기 때문에 표에서 제외)</li>
</ul>
<table class="table">
        <thead><tr>
<th>a</th>
<th>b</th>
<th>c</th>
<th>a ~ b 거리</th>
<th>b ~ c 거리</th>
<th>c ~ a 거리</th>
<th><code>f(a, b, c)</code></th>
</tr>
</thead>
        <tbody><tr>
<td>1</td>
<td>2</td>
<td>3</td>
<td>1</td>
<td>1</td>
<td>2</td>
<td>1</td>
</tr>
<tr>
<td>1</td>
<td>2</td>
<td>4</td>
<td>1</td>
<td>2</td>
<td>3</td>
<td>2</td>
</tr>
<tr>
<td>1</td>
<td>3</td>
<td>4</td>
<td>2</td>
<td>1</td>
<td>3</td>
<td>2</td>
</tr>
<tr>
<td>2</td>
<td>3</td>
<td>4</td>
<td>1</td>
<td>1</td>
<td>2</td>
<td>1</td>
</tr>
</tbody>
      </table>
<ul>
<li>따라서, 2를 return 해야 합니다.</li>
</ul>

<p>입출력 예 #2</p>

<ul>
<li>다음 그림은 입력으로 주어진 트리를 나타낸 것입니다.</li>
</ul>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/c5dbbcaf-19c5-4770-8b7f-1f65db858009/ex2.png" title="" alt="ex2.png"></p>

<ul>
<li>f값에 사용될 3개의 점으로 (1, 2, 3), (2, 3, 4) 등을 고를 때 가장 큰 값인 2를 얻을 수 있으므로, 2를 return 해야 합니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges