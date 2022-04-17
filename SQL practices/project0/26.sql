SELECT Trainer.name, SUM(CatchedPokemon.level) as sum_lvl
FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
GROUP BY Trainer.name
ORDER BY sum_lvl DESC LIMIT 1