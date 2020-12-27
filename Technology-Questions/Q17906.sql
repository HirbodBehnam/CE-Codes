-- Section1
    INSERT INTO `Player` (`id`, `team`, `age`) SELECT `id`, "Chelsea", 24 FROM `Person` WHERE ((`id` NOT IN (SELECT `id` FROM `Player`)) AND (`id` NOT IN (SELECT `id` FROM `Coach`)) AND (`id` NOT IN (SELECT `id` FROM `Refree`)));
-- Section2
    SELECT c.id, p.name FROM `Coach` c INNER JOIN `Person` p ON c.id = p.id WHERE ((c.id IN (SELECT `id` FROM `Player`)) AND (c.team NOT IN (SELECT `team` FROM `Player` WHERE `id`=c.id)));
-- Section3
    ALTER TABLE `Player` ADD FOREIGN KEY (team) REFERENCES Team(name) ON DELETE CASCADE;