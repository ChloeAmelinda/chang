// Hàm kiểm tra một từ có lặp ký tự không
function khongLapKyTu(word: string): boolean {
    let words =word.split("");
    for (let i = 0; i < word.length; i++) {
        for (let j = i + 1; j < word.length; j++) {
            if (words[i] === words[j]) {
                return false; // Từ có lặp ký tự
            }
        }
    }
    return true; // Từ không có lặp ký tự
}


function timTuDaiNhat(cau: string): string {
    const cacTu = cau.split(" ");
    let ketQua = "";

    for (let tu of cacTu) {
        if (khongLapKyTu(tu) && tu.length > ketQua.length) {
            ketQua = tu;
        }
    }

    return ketQua;
}

// Test thử
const input = "hello world apple banana orange pumpkin cucumber";
const output = timTuDaiNhat(input);
console.log(output); 