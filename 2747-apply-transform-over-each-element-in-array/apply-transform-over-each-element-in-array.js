/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
    let newArr = [];
    arr.map((num, i) => {
        newArr.push(fn(num, i))
    })
    return newArr;
};