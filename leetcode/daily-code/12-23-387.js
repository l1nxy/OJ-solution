/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    for(ch of s){
        if(s.indexOf(ch) == s.lastIndexOf(ch)){
            return s.indexOf(ch);
        }
    }
    return -1;
};
