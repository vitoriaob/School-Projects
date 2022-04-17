SELECT CatchedPokemon.nickname
FROM (CatchedPokemon
INNER JOIN Gym ON Gym.leader_id = CatchedPokemon.owner_id 
              AND Gym.city = 'Sangnok City'
INNER JOIN Pokemon ON Pokemon.id = CatchedPokemon.pid 
)
WHERE Pokemon.type = 'Water'
GROUP BY CatchedPokemon.nickname
ORDER BY CatchedPokemon.nickname