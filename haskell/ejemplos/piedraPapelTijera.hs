data Jugada = Piedra | Papel | Tijera
  deriving (Show, Eq)

gana :: Jugada -> Jugada
gana Piedra = Papel
gana Papel = Tijera
gana Tijera = Piedra

pierde ::Jugada -> Jugada
pierde Piedra = Tijera
pierde Papel = PIedra
pierde Tijera = Papel

type Juego = ([Jugada], [Jugada])


