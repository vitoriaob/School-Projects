SELECT SUM(CatchedPokemon.level) as "Total Level"
FROM (CatchedPokemon
INNER JOIN Pokemon ON Pokemon.id = CatchedPokemon.pid)
WHERE Pokemon.type = 'Fire'
