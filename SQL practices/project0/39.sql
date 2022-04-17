SELECT Pokemon.name
FROM (Gym
INNER JOIN Trainer ON Gym.leader_id = Trainer.id
INNER JOIN CatchedPokemon ON CatchedPokemon.owner_id = Trainer.id
INNER JOIN Pokemon ON Pokemon.id = CatchedPokemon.pid)
WHERE Gym.city = 'Rainbow City'
GROUP BY Pokemon.name
ORDER BY Pokemon.name;
