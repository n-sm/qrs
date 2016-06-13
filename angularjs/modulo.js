
function f(a,d)
{
    if(a < d) return(a)
    else return (f(a-d, d))
};

var i = 9991;
var j = 3;
var n = f(i,j);
document.write("modulo " + i + " " + j + ": "+ n.toString() + "</br>");
//document.write(f(8, 41));
