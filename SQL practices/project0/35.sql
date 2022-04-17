SELECT Trainer.name, COUNT(CatchedPokemon.owner_id) as 'Pokemon caught'
FROM CatchedPokemon, Trainer
WHERE  Trainer.id = CatchedPokemon.owner_id
group by Trainer.name
ORDER BY Trainer.name;