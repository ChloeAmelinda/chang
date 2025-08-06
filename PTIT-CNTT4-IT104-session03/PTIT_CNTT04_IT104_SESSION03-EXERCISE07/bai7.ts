let value:string = "bannana";
let result:string = "";
for(let i of value) {
    if(!result.includes(i)) {
        result += i;
    }
}
console.log(result); // Output: "ban"