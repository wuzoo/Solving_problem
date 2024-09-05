function solution(id_pw, db) {
  let [id, pwd] = id_pw;
  let map = new Map(db);

  return map.has(id) ? (map.get(id) === pwd ? "login" : "wrong pw") : "fail";
}
