
function Opcion(text) {
    this.text = text;
}

Opcion.prototype.print = function(name, value) {
    document.write ('<input type="radio" name="' + name + '" value="' +
		    value + '" checked>' + this.text)
}


function Item(preg,opciones,id) {
    this.preg = preg;
    this.opciones = opciones;
    this.id = id;
}


Item.prototype.print = function() {

    var len = this.opciones.length;
    document.write('<table><th colspan=' + len + '>' +
		  this.preg + '</th><tr>')

    for(var i = 0; i < len; i++) {
	document.write('<td>')	
	this.opciones[i].print(name = 'p' + this.id,
			  value = 'p' + this.id +'o' + i )
	document.write('</td>')	
    }
    
    document.write('</tr></table>')
}
/*
Item.prototype.print = function() {
    str = '<table><th colspan=' + this.opciones.length 
	+ preg + '</th><tr><td>';
    for(var i = 0, max=this.opciones.length; i < max; i++) {
	str += <td> + opciones[i] + </td>;
	
    }
    str += '</tr></table>'
    document.write(str)
}

*/

var opArr = [ new Opcion("opcion 1"),
	      new Opcion("opcion 2"),
	      new Opcion("opcion 3"),
	      new Opcion("opcion 4")];

var pregArr = [ new Item("la primera pregunta", opArr, 'p01'),
		new Item("la segunda pregunta", opArr, 'p02'),
		new Item("la tercera pregunta", opArr, 'p03'),
		new Item("la cuarta pregunta", opArr, 'p04'),
		new Item("la quinta pregunta", opArr, 'p05')]


document.write('<form><ol>')
//opArr[0].print(name='a', value='aa')

for (var i=0, hasta=pregArr.length; i< hasta-1; i++) {

    document.write('<li>')
    pregArr[i].print()
    document.write('</li>')

}
document.write('</ol></form>')

