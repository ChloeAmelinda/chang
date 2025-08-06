function add(a: number | string, b: number | string): number | string {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB)) {
        return "Invalid input";
    }
    return numA + numB;
}

function subtract(a: number | string, b: number | string): number | string {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB)) {
        return "Invalid input";
    }
    return numA - numB;
}

function multiply(a: number | string, b: number | string): number | string {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB)) {
        return "Invalid input";
    }
    return numA * numB;
}

function divide(a: number | string, b: number | string): number | string {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB) || numB === 0) {
        return "Invalid input";
    }
    return numA / numB;
}

function power(base: number | string, exponent: number | string): number | string {
    const numBase = Number(base);
    const numExponent = Number(exponent);
    if (isNaN(numBase) || isNaN(numExponent)) {
        return "Invalid input";
    }
    return Math.pow(numBase, numExponent);
}

function sqrt(base: number | string, root: number | string): number | string {
    const numBase = Number(base);
    const numRoot = Number(root);
    if (isNaN(numBase) || isNaN(numRoot) || numRoot === 0) {
        return "Invalid input";
    }
    if (numBase < 0 && numRoot % 2 === 0) {
        return "Cannot calculate even root of negative number";
    }
    return Math.pow(numBase, 1 / numRoot);
}

function factorial(n: number | string): number | string {
    const numN = Number(n);
    if (isNaN(numN) || !Number.isInteger(numN) || numN < 0) {
        return "Invalid input";
    }
    if (numN === 0 || numN === 1) return 1;
    return numN * (factorial(numN - 1) as number);
}

function calculate(operation: string): void {
    const input1 = (document.getElementById('input1') as HTMLInputElement).value;
    const input2 = (document.getElementById('input2') as HTMLInputElement).value;
   
    const resultDiv = document.getElementById('result') as HTMLDivElement;

    
    resultDiv.textContent = '';

    let result: number | string;
    switch (operation) {
        case 'add':
            result = add(input1, input2);
            break;
        case 'subtract':
            result = subtract(input1, input2);
            break;
        case 'multiply':
            result = multiply(input1, input2);
            break;
        case 'divide':
            result = divide(input1, input2);
            break;
        case 'power':
            result = power(input1, input2);
            break;
        case 'sqrt':
            result = sqrt(input1, input2);
            break;
        case 'factorial':
            result = factorial(input1);
            break;
        default:
            result = "Invalid operation";
    }

   
        resultDiv.textContent = `Result: ${result}`;
    
}