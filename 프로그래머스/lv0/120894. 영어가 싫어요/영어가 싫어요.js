function solution(numbers) {
  const numarr = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  ];

  let str = numbers;

  numarr.map((item, index) => {
    str = str.replaceAll(item, index.toString());
    // str = str.split(item).join(index.toString());
  });

  return +str;
}
