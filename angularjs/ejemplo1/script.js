angular.module("root", [])
    .controller("index", [function($scope) {
	vm = this;
	vm.mensaje = "Hello World";
	vm.foo = function(x) {
	    var n = x + 1;
	    return(n);
	};
}]);
