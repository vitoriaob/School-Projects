SELECT name
FROM (Trainer
INNER JOIN Gym ON Gym.leader_id = Trainer.id)
WHERE Gym.city = 'Brown City';
