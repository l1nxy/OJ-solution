/**
 * @param {number[]} ratings
 * @return {number}
 */
var candy = function(ratings) {
    let ret = new Array(ratings.length);
    for(let i=0; i < ratings.length;i++){
        if(i > 0 && ratings[i] > ratings[i-1]){
            ret[i] = ret[i-1] +1;
        }else{
            ret[i] = 1;
        }
    }

    //ret.map(a => console.log(a));
    for(let i=ratings.length; i >0;i--){
        if(ratings[i] < ratings[i-1]){
            ret[i-1] = Math.max(ret[i-1],ret[i]+1);
        }
    }

//ret.map(a => console.log(a));
    let sum = 0;
    for(s of ret){
        sum += s;
    }

    return sum;

};
