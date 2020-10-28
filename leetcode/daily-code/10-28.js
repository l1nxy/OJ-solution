/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
        const count = new Map();
        for(const x of arr){
            if(count.has(x)){
                count.set(x,count.get(x) +1);
            }else{
                count.set(x,1);
            }
        }
        const m = new Set();
        for([key,value] of count){
            m.add(value);
        }

    return m.size == count.size
};
