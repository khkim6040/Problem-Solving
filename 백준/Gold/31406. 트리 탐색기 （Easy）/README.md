# [Gold II] 트리 탐색기 (Easy) - 31406 

[문제 링크](https://www.acmicpc.net/problem/31406) 

### 성능 요약

메모리: 2204 KB, 시간: 12 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 구현, 트리

### 제출 일자

2024년 3월 30일 12:13:58

### 문제 설명

<p>당신은 폴더 구조를 손쉽게 탐색할 수 있는 트리 탐색기 기능을 개발하고 있습니다.</p>

<p>폴더에는 $1$번부터 $N$번까지 번호가 붙어 있습니다. 폴더는 트리 형태의 계층 구조를 이루고 있어서, 다른 폴더를 하위 폴더로 가질 수 있습니다. 어떤 폴더가 포함하는 폴더란, 그 폴더의 하위 폴더 및 하위 폴더가 포함하는 폴더를 가리킵니다. $1$번 폴더는 최상위 폴더로, 다른 모든 폴더를 포함하고 있습니다.</p>

<p>트리 탐색기는 목록에 $1$번 폴더의 하위 폴더들을 표시합니다. ($1$번 폴더는 표시하지 않습니다.) 폴더는 펼치거나 접을 수 있습니다. 처음에는 모든 폴더가 접혀 있는 상태입니다. 폴더를 펼치면 그 하위 폴더들이 펼친 폴더 바로 아래에 들여쓰기되어 표시됩니다. 폴더를 접으면 포함된 모든 폴더가 목록에서 사라집니다. 폴더를 접었다가 다시 펼쳤을 때, 포함된 모든 폴더는 이전의 접힘/펼침 상태를 유지합니다. (그림 1)</p>

<p style="text-align: center;"><img alt="폴더를 펼치고 접는 예제. ▽은 열린 폴더를, ▶은 닫힌 폴더를 나타낸다." src="https://upload.acmicpc.net/0a7bd75e-481b-42d0-8106-bbbd7164d6fc/-/preview/" style="max-width: 100%;" width="500px"></p>

<p style="text-align: center;">(그림 1) 폴더를 펼치고 접는 예제. ▽은 펼쳐진 폴더를, ▶은 접힌 폴더를 나타냅니다.</p>

<p>당신은 트리 탐색기에 커서 기능을 추가하려고 합니다. 커서는 처음에 $1$번 폴더의 첫 번째 하위 폴더를 가리키고 있습니다. 당신은 두 가지 명령어를 구현해야 합니다.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>move</code></span> $k$ : 커서를 $k$만큼 아래로 이동합니다. ($k$가 음수라면 $-k$만큼 위로 이동합니다.) 커서를 이동하다가 목록의 시작이나 끝에 도달하면 더이상 이동하지 않습니다. (그림 2)</li>
	<li><span style="color:#e74c3c;"><code>toggle</code></span> : 커서가 가리키는 폴더를 접거나 펼칩니다. 폴더가 접혀 있었다면 펼치고, 펼쳐져 있었다면 접습니다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4001134d-cdc5-4fcd-a25e-19f06dfbc67a/-/preview/" style="max-width: 100%;" width="500px"></p>

<p style="text-align: center;">(그림 2) <span style="color:#e74c3c;"><code>move</code></span> 명령어를 사용하는 예제</p>

<p>주어진 $Q$개의 명령어를 모두 수행하는 프로그램을 작성하세요.</p>

### 입력 

 <p>첫 줄에 폴더의 수 $N$과 명령의 수 $Q$가 공백으로 구분되어 주어집니다. $(2 \le N \le 2\,000;$ $1 \le Q \le 2\,000)$</p>

<p>다음 $N$개의 줄에 폴더의 계층 구조가 주어집니다. 그중 $i$번째 줄에는 $i$번 폴더의 하위 폴더 개수와 하위 폴더 번호가 표시되는 순서대로 공백으로 구분되어 주어집니다. 주어진 계층 구조에서 두 폴더가 서로를 포함하는 관계나, 두 폴더가 동일한 하위 폴더를 공유하는 경우는 없습니다.</p>

<p>다음 $Q$개의 줄에 수행해야 하는 명령어가 한 줄에 하나씩 차례로 주어집니다. <span style="color:#e74c3c;"><code>move</code></span> 명령어와 함께 주어지는 수 $k$는 절댓값이 $N$을 넘지 않습니다. <span style="color:#e74c3c;"><code>move</code></span> 명령어는 적어도 하나 이상 주어집니다.</p>

### 출력 

 <p><span style="color:#e74c3c;"><code>move</code></span> 명령어를 수행할 때마다, 이동 후 커서가 위치한 폴더의 번호를 한 줄에 하나씩 출력하세요.</p>

