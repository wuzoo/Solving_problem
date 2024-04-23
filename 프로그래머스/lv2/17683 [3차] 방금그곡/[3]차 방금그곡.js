const MAP = {
  "C#": "c",
  "B#": "b",
  "D#": "d",
  "F#": "f",
  "G#": "g",
  "A#": "a",
};

function getDuration(start, end) {
  const [hs, ms] = start.split(":");
  const [he, me] = end.split(":");

  return (+he - +hs) * 60 + +me - +ms;
}

function getFullMusic(musicinfo, duration) {
  const repeatCnt = Math.ceil(duration / musicinfo.length);
  const fullMusic = musicinfo.repeat(repeatCnt).slice(0, duration);

  return fullMusic;
}

function convert(str) {
  Object.keys(MAP).forEach((key) => {
    str = str.replaceAll(key, MAP[key]);
  });
  return str;
}

function solution(m, musicinfos) {
  let answer = [];

  musicinfos.forEach((str) => {
    let [start, end, name, music] = str.split(",");

    const duration = getDuration(start, end);
    const fullMusic = getFullMusic(convert(music), duration);

    answer.push([duration, fullMusic, name]);
  });

  answer.sort((a, b) => b[0] - a[0]);
  answer = answer.filter((arr) => arr[1].indexOf(convert(m)) !== -1);

  return answer.length ? answer[0][2] : "(None)";
}
