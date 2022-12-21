primes = []

for (let i = 2; i <= 250; i++) {
  let isPrime = true;
  for (let j = 2; j <= Math.sqrt(i); j++) {
    if (i % j == 0) {
      isPrime = false;
      break;
    }
  }
  if (isPrime) {
    primes.push(i);
  }
}

console.log("All primes between 2 and 250 are:");
console.log(...primes);

