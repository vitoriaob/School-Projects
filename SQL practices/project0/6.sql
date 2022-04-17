SELECT name, AVG(CatchedPokemon.level) AS Catched_Av_lvl
FROM CatchedPokemon, (Gym
INNER JOIN Trainer ON Trainer.id = Gym.leader_id)
WHERE CatchedPokemon.owner_id = Trainer.id 
GROUP BY name
ORDER BY name;