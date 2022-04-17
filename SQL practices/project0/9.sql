SELECT Trainer.name, CatchedPokemon.nickname
FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
WHERE CatchedPokemon.level in
(SELECT MAX(CatchedPokemon.level) 
 FROM CatchedPokemon
 GROUP BY CatchedPokemon.owner_id 
 HAVING COUNT(CatchedPokemon.owner_id) >= 4)
ORDER BY CatchedPokemon.nickname