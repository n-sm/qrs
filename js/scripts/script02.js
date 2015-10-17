newitem = function(pregunta, opciones, id)
{
    document.write('<table><th colspan=4>' + pregunta  + '</th><tr>')
    for(var i=0;i<4;i++) {
	document.write('<td><input type="radio" name="p00'+id+'" \
                       value="op'+i+'"checked>' + opciones[i] + '</td>')
    }
    document.write('</tr></table>')
}
var arr = new Array(4);
for(var i=0;i<4;i++) {
    arr[i]= "Opcion " + (i+1);
}

newitem('Pregunta numero uno ...:', arr,1)
newitem("Pregunta numero dos", arr,2)
newitem("la pregunta numero tres", arr,3)
