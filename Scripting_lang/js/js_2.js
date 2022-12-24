const inputString = prompt("Enter a string:");

let numWords = 0;
let numChars = 0;
let numVowels = 0;
let numConsonants = 0;

// const words = inputString.split(" ");

// numWords = words.length;
// numChars = inputString.length;

if (inputString) {
  numWords = 1;
  for (let i = 0; i < inputString.length; i++) {
    let ch = inputString[i].toLowerCase();

    if (ch == ' ') {
      numWords++;
    }
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      numVowels++;
    } else if (ch >= 'a' && ch <= 'z') {
      numConsonants++;
    }

    numChars++;
  }
}

console.log(`Number of words: ${numWords}`);
console.log(`Number of characters: ${numChars}`);
console.log(`Number of vowels: ${numVowels}`);
console.log(`Number of consonants: ${numConsonants}`);
