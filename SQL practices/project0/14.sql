SELECT Trainer.hometown 
FROM Trainer
GROUP BY Trainer.hometown
ORDER BY COUNT(Trainer.hometown) DESC
LIMIT 1
