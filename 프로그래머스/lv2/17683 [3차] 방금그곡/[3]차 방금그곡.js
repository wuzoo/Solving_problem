const MAP = {
  "C#": "c",
  "B#": "b",
  "D#": "d",
  "F#": "f",
  "G#": "g",
  "A#": "a",
};

const changeMusic = (music) => {
  Object.keys(MAP).forEach((char) => {
    music = music.replaceAll(char, MAP[char]);
  });
  return music;
};

const getTime = (start, end) => {
  let [h, m] = start.split(":");
  let [he, me] = end.split(":");
  return +me - +m + (+he - +h) * 60;
};

function solution(m, musicinfos) {
  let result = [];
  m = changeMusic(m);

  musicinfos.forEach((item) => {
    const [start, end, name, music] = item.split(",");

    const time = getTime(start, end);
    const melody = changeMusic(music);
    const converted = melody
      .repeat(Math.ceil(time / melody.length))
      .slice(0, time);

    result.push([time, converted, name]);
  });

  result.sort((a, b) => b[0] - a[0]);
  result = result.filter((value) => value[1].indexOf(m) !== -1);

  if (result.length === 0) return "(None)";

  return result[0][2];
}
