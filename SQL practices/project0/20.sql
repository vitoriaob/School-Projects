SELECT Trainer.name
FROM (Trainer
INNER JOIN Gym ON Gym.leader_id = Trainer.id) 
ORDER BY name;