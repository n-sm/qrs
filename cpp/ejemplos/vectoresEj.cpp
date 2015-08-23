// Un argumento Allocator con default.
// Construye un vector vac'io.
explicit vector(const Allocator &a = allocator());
//ejemplo:
vector<int>();

// Tres argumentos. Dos con default. Uno sin: num (de type T).
// Construye tiene num elementos de valor val.
explicit vector(size_type num, const T &val = T(), const Allocator &a = Allocator());
//ejemplo:
vector<int> mi_vector(3); // vector de 3 ints
vector<char> mi_vector(11, 'b') // vector de 11 'b's

