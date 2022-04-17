SELECT DISTINCT Trainer.name
FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
WHERE  CatchedPokemon.owner_id in (SELECT CatchedPokemon.owner_id
 FROM CatchedPokemon
 GROUP BY CatchedPokemon.pid, CatchedPokemon.owner_id
 HAVING COUNT(CatchedPokemon.pid) >=2 )
 ORDER BY Trainer.name