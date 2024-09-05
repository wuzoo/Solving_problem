function solution(files) {
  const regexp = /\d+/;
  function compare(a, b) {
    const num1 = a.match(regexp);
    const num2 = b.match(regexp);

    const idx1 = a.indexOf(num1);
    const idx2 = b.indexOf(num2);

    const head1 = a.slice(0, idx1).toLowerCase();
    const head2 = b.slice(0, idx2).toLowerCase();

    for (let i = 0; i < Math.min(head1.length, head2.length); ++i) {
      if (head1.charCodeAt(i) !== head2.charCodeAt(i)) {
        return head1.charCodeAt(i) - head2.charCodeAt(i);
      }
    }
    if (head1.length !== head2.length) {
      return head1.length - head2.length;
    }
    if (+num1 !== +num2) {
      return +num1 - +num2;
    }
  }

  return files.sort((a, b) => compare(a, b));
}
