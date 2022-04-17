SELECT  Pokemon.type, COUNT(CatchedPokemon.pid) as Num_of_Pokemons
FROM (Pokemon
INNER JOIN CatchedPokemon ON Pokemon.id = CatchedPokemon.pid)
GROUP BY Pokemon.type
ORDER BY type;