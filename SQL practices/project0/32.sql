SELECT DISTINCT name, nickname, CatchedPokemon.level FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
WHERE owner_id
IN (SELECT owner_id FROM (CatchedPokemon INNER JOIN Pokemon ON CatchedPokemon.pid = Pokemon.id) GROUP BY owner_id HAVING COUNT(DISTINCT type) = 1)