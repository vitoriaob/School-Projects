SELECT Trainer.name
FROM (CatchedPokemon
INNER JOIN Trainer ON Trainer.id = CatchedPokemon.owner_id
INNER JOIN Pokemon ON Pokemon.id = CatchedPokemon.pid)
WHERE  Pokemon.name LIKE 'P%' and Trainer.hometown = 'Sangnok City' 
GROUP BY Trainer.name, Pokemon.name
ORDER BY Trainer.name;

