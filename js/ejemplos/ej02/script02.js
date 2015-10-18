pr = function(str) { document.write(str) }

function foo() {
    var x = document.getElementById("inputTextBox").value;
    var y = document.getElementById("output").innerHTML;
    document.getElementById("output").innerHTML = y +'<br>'+ x;
}
