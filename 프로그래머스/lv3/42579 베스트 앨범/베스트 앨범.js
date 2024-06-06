function solution(genres, plays) {
  var answer = [];
  const genreMap = {};
  const playMap = new Map();

  genres.forEach((genre, idx) => {
    genreMap[genre] = (genreMap[genre] ?? 0) + plays[idx];
    playMap.set(idx, {
      genre,
      play: plays[idx],
    });
  });

  const sortedGenre = Object.keys(genreMap).sort(
    (a, b) => genreMap[b] - genreMap[a]
  );
  let sortedPlay = [];

  sortedGenre.forEach((genre) => {
    for (let [key, value] of playMap) {
      if (value.genre === genre) {
        sortedPlay.push({
          idx: key,
          play: value.play,
        });
      }
    }
    sortedPlay.sort((a, b) => b.play - a.play);
    sortedPlay.slice(0, 2).forEach((item) => answer.push(item.idx));
    sortedPlay = [];
  });

  return answer;
}
