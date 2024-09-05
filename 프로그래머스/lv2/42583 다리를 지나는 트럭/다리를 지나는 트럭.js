function solution(bridge_length, weight, truck_weights) {
  let current_time = 0;
  let current_weight = 0;
  const passing = [];

  while (truck_weights.length || passing.length) {
    const current = truck_weights[0];
    if (current_weight + current <= weight && passing.length < bridge_length) {
      current_weight += truck_weights.shift();
      passing.push([current, current_time + bridge_length]); // [무게, 나갈 시간]
      current_time++;
    } else {
      const [truck, exitSec] = passing.shift();
      if (current_time < exitSec) {
        current_time = exitSec;
      }
      current_weight -= truck;
    }
  }
  return current_time + 1;
}
