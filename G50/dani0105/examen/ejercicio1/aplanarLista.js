function aplanarMap(array) {
    var ret = [];
    array.map( element => {
        if(Array.isArray(element)){
            ret = ret.concat(aplanarMap(element));
        }
        else
            ret.push(element);
    });
    return ret;
}