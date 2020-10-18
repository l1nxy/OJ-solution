var removeNthFromEnd = function(head, n) {
    var ret = head;
    var temp = head;
    while(n--){ head = head.next;}
    if(head == null){
        return ret.next;
    }
    while(head.next!= null){
        temp = temp.next;
        head = head.next;
    }
    temp.next = temp.next.next;
    return ret;
};
