SELECT Trainer.name 
FROM Trainer
WHERE Trainer.id NOT IN (SELECT Gym.leader_id FROM Gym);