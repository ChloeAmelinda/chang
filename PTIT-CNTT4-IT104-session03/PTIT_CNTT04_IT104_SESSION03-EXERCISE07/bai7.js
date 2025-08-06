"use strict";

let value = "bannana";
let result = "";
for (let i of value) {
    if (!result.includes(i)) {
        result += i;
    }
}
console.log(result); // Output: "ban"
//# sourceMappingURL=bai7.js.map