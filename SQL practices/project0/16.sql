SELECT Trainer.name
FROM (Gym
INNER JOIN Trainer ON Trainer.id = Gym.leader_id
INNER JOIN City ON City.name = Gym.city)
WHERE  City.description = 'Amazon'
GROUP BY Trainer.name;
