function solution(numbers, hand) {
  let answer = "";

  let leftmap = [1, 4, 7];
  let rightmap = [3, 6, 9];
  let midmap = [2, 5, 8, 0];

  let curright = [2, 3]; // map 상 idx
  let curleft = [0, 3];

  numbers.map((num) => {
    if (rightmap.includes(num)) {
      curright[0] = 2;
      curright[1] = rightmap.indexOf(num);
      answer += "R";
    } else if (leftmap.includes(num)) {
      curleft[0] = 0;
      curleft[1] = leftmap.indexOf(num);
      answer += "L";
    } else {
      let curidx = [1, midmap.indexOf(num)];
      let rightdistance =
        Math.abs(curidx[0] - curright[0]) + Math.abs(curidx[1] - curright[1]);
      let leftdistance =
        Math.abs(curidx[0] - curleft[0]) + Math.abs(curidx[1] - curleft[1]);

      if (leftdistance === rightdistance) {
        if (hand === "right") {
          answer += "R";
          curright = Array.from(curidx);
        } else {
          answer += "L";
          curleft = Array.from(curidx);
        }
      } else {
        if (leftdistance > rightdistance) {
          answer += "R";
          curright = Array.from(curidx);
        } else {
          answer += "L";
          curleft = Array.from(curidx);
        }
      }
    }
  });

  return answer;
}
