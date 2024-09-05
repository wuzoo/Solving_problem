class MinHeap {
  constructor() {
    this.heap = [null];
  }

  size() {
    return this.heap.length - 1;
  }

  getMin() {
    return this.heap[1] ? this.heap[1] : null;
  }

  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }

  push(value) {
    this.heap.push(value);
    let curIdx = this.heap.length - 1;
    let parIdx = (curIdx / 2) >> 0;

    while (curIdx > 1 && this.heap[parIdx] > this.heap[curIdx]) {
      this.swap(parIdx, curIdx);
      curIdx = parIdx;
      parIdx = (curIdx / 2) >> 0;
    }
  }

  pop() {
    const min = this.heap[1];
    if (this.heap.length <= 2) this.heap = [null];
    else this.heap[1] = this.heap.pop();

    let curIdx = 1;
    let leftIdx = curIdx * 2;
    let rightIdx = curIdx * 2 + 1;

    if (!this.heap[leftIdx]) return min;
    if (!this.heap[rightIdx]) {
      if (this.heap[leftIdx] < this.heap[curIdx]) {
        this.swap(leftIdx, curIdx);
      }
      return min;
    }

    while (
      this.heap[leftIdx] < this.heap[curIdx] ||
      this.heap[rightIdx] < this.heap[curIdx]
    ) {
      const minIdx =
        this.heap[leftIdx] > this.heap[rightIdx] ? rightIdx : leftIdx;
      this.swap(minIdx, curIdx);
      curIdx = minIdx;
      leftIdx = curIdx * 2;
      rightIdx = curIdx * 2 + 1;
    }

    return min;
  }
}

const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin[0];
const M = +stdin[1];

const edges = stdin.slice(2, M + 2).map((str) => str.split(" ").map(Number));

const [start, end] = stdin.at(-1).split(" ").map(Number);

function solution() {
  const graph = Array.from(Array(N + 1), () => []);
  const d = Array.from({ length: N + 1 }, () => 1e9);

  edges.forEach((item) => {
    const [start, to, cost] = item;

    graph[start].push([to, cost]);
  });

  const q = new MinHeap();
  q.push([start, 0]);
  d[start] = 0;

  while (q.size()) {
    const [curNode, curCost] = q.pop();

    if (d[curNode] < curCost) continue;

    for (const v of graph[curNode]) {
      const next = v[0];
      const dist = curCost + v[1];

      if (dist < d[next]) {
        q.push([next, dist]);
        d[next] = dist;
      }
    }
  }

  console.log(d[end]);
}

solution();
