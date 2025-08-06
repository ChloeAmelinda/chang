"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function add(a, b) {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB)) {
        return "Invalid input";
    }
    return numA + numB;
}
function subtract(a, b) {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB)) {
        return "Invalid input";
    }
    return numA - numB;
}
function multiply(a, b) {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB)) {
        return "Invalid input";
    }
    return numA * numB;
}
function divide(a, b) {
    const numA = Number(a);
    const numB = Number(b);
    if (isNaN(numA) || isNaN(numB) || numB === 0) {
        return "Invalid input";
    }
    return numA / numB;
}
function power(base, exponent) {
    const numBase = Number(base);
    const numExponent = Number(exponent);
    if (isNaN(numBase) || isNaN(numExponent)) {
        return "Invalid input";
    }
    return Math.pow(numBase, numExponent);
}
function sqrt(base, root) {
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
function factorial(n) {
    const numN = Number(n);
    if (isNaN(numN) || !Number.isInteger(numN) || numN < 0) {
        return "Invalid input";
    }
    if (numN === 0 || numN === 1)
        return 1;
    return numN * factorial(numN - 1);
}
function calculate(operation) {
    const input1 = document.getElementById('input1').value;
    const input2 = document.getElementById('input2').value;
    const resultDiv = document.getElementById('result');
    resultDiv.textContent = '';
    let result;
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
//# sourceMappingURL=bai9.js.map