function add(a: number | string, b: number | string): number | string {
  const numA = Number(a);
  const numB = Number(b);
  if (isNaN(numA) || isNaN(numB)) {
    return "Invalid input";
  }
  return numA + numB;
}

// Similarly for subtract, multiply, divide:
function subtract(a: number | string, b: number | string): number | string {
  const numA = Number(a);
  const numB = Number(b);
  return isNaN(numA) || isNaN(numB) ? "Invalid input" : numA - numB;
}

function multiply(a: number | string, b: number | string): number | string {
  const numA = Number(a);
  const numB = Number(b);
  return isNaN(numA) || isNaN(numB) ? "Invalid input" : numA * numB;
}

function divide(a: number | string, b: number | string): number | string {
  const numA = Number(a);
  const numB = Number(b);
  if (isNaN(numA) || isNaN(numB) || numB === 0) {
    return "Invalid input";
  }
  return numA / numB;
}
console.log(add(5, 10)); 
console.log(subtract(10, 5));
console.log(multiply(5, 10)); 
console.log(divide(10, 2)); 