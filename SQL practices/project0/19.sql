SELECT SUM(CatchedPokemon.level)
FROM  (CatchedPokemon
INNER JOIN Trainer ON Trainer.id = CatchedPokemon.owner_id)
WHERE  Trainer.name = 'Matis';

