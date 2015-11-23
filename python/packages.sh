# /bin/bash

# Paquetes instalados
#
# Con apt-get
# python-dev python-dev3
##
#
sudo apt-get install python3-dev python3-pandas
#
# Desde codigo fuente
# mpmath sympy
##
#
# Directorio para bajar las fuentes:
SRCDIR=$HOME/src
CWD=$PWD
if [[ ! -d $SRCDIR ]]; then mkdir $SRCDIR; fi
#

# Funcion para instalar modulos python desde git
instmod () {
    SRCDIR=$HOME/src
    CWD=$PWD
    if [[ $# -ne 2 ]]
    if [[ ! -d $SRCDIR ]]; then mkdir $SRCDIR; fi
    then
	echo "uso:"
	echo "instmod URL nombre"
	return 0
    fi
    nombre=$2
    url=$1
    if [[ ! -d $SRCDIR/$nombre ]]
    then
	git clone $url $nombre
    fi
    cd $SRCDIR/sympy && sudo python3 setup.py install
    cd $CWD
    }
    
    
## sympy
#
instmod git://github.com/sympy/sympy.git sympy
instmod git://gitthub.com/fredrik-johansson/mpmath.git mpmath

## numpy
#

## primero instalat Cython!
##instmod http://github.com/numpy/numpy.git numpy
