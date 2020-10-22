var partitionLabels = function(S) {
  var pos = new Array(26);
  const cpa = 'a'.charCodeAt(0);
  for (var i = 0; i < S.length; ++i) {
    pos[S.charCodeAt(i) - cpa] = i;
  }

  var ret = new Array();
  var start = 0;
  var end = 0;
  for (var i = 0; i < S.length; ++i) {
    end = Math.max(end, pos[S.charCodeAt(i) - cpa]);
    if (end == i) {
      ret.push(end - start + 1);
      start = end + 1;
    }
  }
  return ret;
};
