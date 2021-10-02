function colorCode(input: string[]): number {
  return Number(
      input
          .map((input) => COLORS.indexOf(input.toLocaleLowerCase()))
          .join("")
          .slice(0, 2)
  );
}

export const COLORS = [
  "black",
  "brown",
  "red",
  "orange",
  "yellow",
  "green",
  "blue",
  "violet",
  "grey",
  "white",
];

export default colorCode;

console.log(`['BLACK']`, `|${colorCode(["Black"])}`); // 0
console.log(`['ORANGE', 'GREEN']`, `|${colorCode(["ORANGE", "GREEN"])}`); //35
console.log(`['GREY', 'RED']`, `|${colorCode(["GREY", "RED"])}`); // 82
console.log(
    `['VIOLET', 'RED', 'WHITE']`,
    `|${colorCode(["VIOLET", "RED", "WHITE"])}`
); // 72 (the third element is not considered)
