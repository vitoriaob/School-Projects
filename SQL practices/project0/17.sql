SELECT AVG(CatchedPokemon.level)
FROM  (CatchedPokemon
INNER JOIN Trainer ON Trainer.id = CatchedPokemon.owner_id
INNER JOIN Pokemon ON Pokemon.id = CatchedPokemon.pid)
WHERE  Pokemon.type = 'Water';
