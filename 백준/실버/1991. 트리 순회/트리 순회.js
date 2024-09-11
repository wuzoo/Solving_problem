const fs = require("fs");
const stdin = fs.readFileSync("ex.txt").toString().trim().split("\n");

const N = +stdin.shift();

const input = stdin.map((str) => str.split(" "));

function solution() {
  const tree = {};

  input.forEach((item) => {
    const [node, left, right] = item;

    tree[node] = [left, right];
  });

  let preorder_result = [];
  function preorder(node) {
    if (node === ".") return;

    const [left, right] = tree[node];

    preorder_result.push(node);

    preorder(left);
    preorder(right);
  }

  let inorder_result = [];
  function inorder(node) {
    if (node === ".") return;

    const [left, right] = tree[node];

    inorder(left);

    inorder_result.push(node);

    inorder(right);
  }

  let postorder_result = [];
  function postorder(node) {
    if (node === ".") return;

    const [left, right] = tree[node];

    postorder(left);
    postorder(right);

    postorder_result.push(node);
  }

  inorder("A");
  preorder("A");
  postorder("A");

  console.log(preorder_result.join(""));
  console.log(inorder_result.join(""));
  console.log(postorder_result.join(""));
}

solution();
