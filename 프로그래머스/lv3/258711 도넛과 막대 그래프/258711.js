function solution(edges) {
  var answer = [0, 0, 0, 0];

  const inEdges = new Array(1000001).fill(0);
  const outEdges = new Array(1000001).fill(0);
  const originEdges = [];

  edges.forEach(([st, en]) => {
    outEdges[st]++;
    inEdges[en]++;
  });

  for (let i = 0; i < inEdges.length; ++i) {
    if (inEdges[i] == 0 && outEdges[i] >= 2) {
      answer[0] = i;
      break;
    }
  }

  const startsNode = [];
  edges.forEach((node) => {
    if (node[0] != answer[0]) {
      originEdges.push(node);
    } else {
      startsNode.push(node[1]);
      inEdges[node[1]]--;
    }
  });

  const graph = Array.from(Array(1000001), () => []);

  originEdges.forEach(([st, en]) => graph[st].push(en));

  for (let i = 0; i < startsNode.length; ++i) {
    const curNode = startsNode[i];
    const len = inEdges[curNode] + outEdges[curNode];

    if (len === 4) answer[3]++;
    else if (len <= 1) answer[2]++;
    else {
      let node = curNode;
      while (true) {
        node = graph[node].pop();
        const l = inEdges[node] + outEdges[node];

        if (l === 4) {
          answer[3]++;
          break;
        }
        if (l <= 1) {
          answer[2]++;
          break;
        }
        if (node === curNode) {
          answer[1]++;
          break;
        }
      }
    }
  }

  return answer;
}
