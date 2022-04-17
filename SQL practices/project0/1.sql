SELECT Trainer.name 
FROM (CatchedPokemon
INNER JOIN Trainer ON Trainer.id = CatchedPokemon.owner_id)
GROUP BY name 
HAVING COUNT(CatchedPokemon.owner_id)>2
ORDER BY COUNT(CatchedPokemon.owner_id);