function solution(new_id) {
  let str = new_id;

  str = str
    .toLowerCase()
    .replace(/[^a-z0-9\-\_\.]/g, (v) => "")
    .replace(/\.{2,}/g, (v) => ".")
    .replace(/(^\.|\.$)/g, (v) => "")
    .replace(/^$/g, (v) => "a")
    .slice(0, 15)
    .replace(/\.$/g, (v) => "");

  if (str.length <= 2) {
    let lastword = str[str.length - 1];
    while (str.length < 3) {
      str += lastword;
    }
  }

  return str;
}
