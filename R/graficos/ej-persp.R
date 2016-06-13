x=y=seq(-5,5,by=0.1)
f=function(x,y){return((x^3)+(y^3))}
persp(outer(x,y,f),shade=T)
