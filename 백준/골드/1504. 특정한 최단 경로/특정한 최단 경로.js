class MinHeap {
  constructor() {
    this.heap = [];
  }

  push(value) {
    this.heap.push(value);
    this.heapifyUp();
  }

  pop() {
    if (this.isEmpty()) return null;

    const root = this.heap[0];
    const lastNode = this.heap.pop();

    if (!this.isEmpty()) {
      this.heap[0] = lastNode;
      this.heapifyDown();
    }

    return root;
  }

  isEmpty() {
    return this.heap.length === 0;
  }

  heapifyUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      if (this.heap[parentIndex] <= this.heap[index]) break;
      [this.heap[parentIndex], this.heap[index]] = [
        this.heap[index],
        this.heap[parentIndex],
      ];
      index = parentIndex;
    }
  }

  heapifyDown() {
    let index = 0;
    const length = this.heap.length;

    while (true) {
      let smallest = index;
      const leftChildIndex = 2 * index + 1;
      const rightChildIndex = 2 * index + 2;

      if (
        leftChildIndex < length &&
        this.heap[leftChildIndex] < this.heap[smallest]
      ) {
        smallest = leftChildIndex;
      }

      if (
        rightChildIndex < length &&
        this.heap[rightChildIndex] < this.heap[smallest]
      ) {
        smallest = rightChildIndex;
      }

      if (smallest === index) break;

      [this.heap[index], this.heap[smallest]] = [
        this.heap[smallest],
        this.heap[index],
      ];
      index = smallest;
    }
  }
}

const fs = require("fs");
const input = fs
  .readFileSync("ex.txt")
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map((v) => +v));

const [N, _] = input.shift();
const [X, Y] = input.pop();
const S = 1;

let adj = Array.from(Array(N + 1), () => []);

input.forEach((x) => {
  const [u, v, w] = x;
  adj[u].push([v, w]);
  adj[v].push([u, w]);
});

function BFS(start) {
  let d = new Array(N + 1).fill(Infinity);
  d[start] = 0;

  let heap = new MinHeap();
  heap.push([start, 0]);

  while (!heap.isEmpty()) {
    let [curNode, curCost] = heap.pop();

    for (const v of adj[curNode]) {
      const node = v[0];
      const dist = v[1] + curCost;
      if (dist < d[node]) {
        heap.push([node, dist]);
        d[node] = dist;
      }
    }
  }

  return d;
}

const distanceS = BFS(S); // 시작점으로부터 출발
const distanceX = BFS(X); // V1으로부터 출발
const distanceY = BFS(Y); // V2으로부터 출발

const result = Math.min(
  distanceS[X] + distanceX[Y] + distanceY[N],
  distanceS[Y] + distanceY[X] + distanceX[N]
);

if (!isFinite(result)) {
  console.log(-1);
} else {
  console.log(result);
}
