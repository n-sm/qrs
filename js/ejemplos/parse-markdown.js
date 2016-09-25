//document.write("javascript:</br>");

var parseItalic = function(str)
{
    var tmp = str.split("_");
    var res = tmp[0];
    var tmplen = tmp.length;
    if (tmplen % 2 == 0)
    {
	tmp.push("");
	tmplen++;
    }
    for (var i = 1; i < tmplen; i++)
    {
	if (i%2 == 1)
	    res = res.concat("<i>", tmp[i]);
	else
	    res = res.concat("</i>", tmp[i]);
    }
    return (res);
};


var parseBold = function(str)
{
    var tmp = str.split("__");
    var res = tmp[0];
    var tmplen = tmp.length;
    if (tmplen % 2 == 0)
    {
	tmp.push("");
	tmplen++;
    }

    for (var i = 1; i < tmp.length; i++)
    {
	if (i%2 == 1)
	    res = res.concat("<b>", tmp[i]);
	else
	    res = res.concat("</b>", tmp[i]);
    }
    return (res);
};


var parseEmph = function(str)
{
    return(parseItalic(parseBold(str)));
};

