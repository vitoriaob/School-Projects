SELECT Trainer.name
FROM (Trainer
INNER JOIN CatchedPokemon ON CatchedPokemon.owner_id = Trainer.id
INNER JOIN Pokemon ON Pokemon.id = CatchedPokemon.pid)
WHERE Pokemon.type = 'Psychic'
GROUP BY Trainer.name
ORDER BY Trainer.name;
