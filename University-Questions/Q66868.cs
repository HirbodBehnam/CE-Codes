using System;
using System.Collections.Generic;
using System.Linq;

namespace Q66868
{
    class Program
    {
        class Player
        {
            public string Name;
            public int Price;
            public int Speed;
            public int Finishing;
            public int Defence;
            /// <summary>
            /// Zero means that this player has no team
            /// </summary>
            public int TeamID;
        }

        class Team
        {
            public string Name;
            public int Money;
            public int PlayersCount;
            public List<Player> Players;
            public int Wins;
            public int Losses;
            public int Ties;
        }
        public static void Main(string[] args)
        {
            var players = new List<Player>();
            var teams = new List<Team>();
            while (true)
            {
                var input = Console.ReadLine().Split(' ');
                if (input[0] == "end")
                {
                    return;
                }else if (input[0] == "new" && input[1] == "player")
                {
                    players.Add(new Player
                    {
                        Name = input[2],
                        Price = int.Parse(input[3]),
                        Speed = int.Parse(input[4]),
                        Finishing = int.Parse(input[5]),
                        Defence = int.Parse(input[6]),
                        TeamID = 0,
                    });
                }else if (input[0] == "new" && input[1] == "team")
                {
                    string name = input[2];
                    if (teams.All(t => t.Name != name))
                    {
                        teams.Add(new Team
                        {
                            Name = name,
                            Money = int.Parse(input[3]),
                            PlayersCount = 0,
                            Players = new List<Player>(11),
                        });
                    }
                }else if (input[0] == "buy")
                {
                    int teamId = int.Parse(input[2]);
                    int playerId = int.Parse(input[1]);
                    if (players.Count < playerId)
                    {
                        Console.WriteLine("player with the id " + playerId + " doesnt exist");
                        continue;
                    }
                    if (teams.Count < teamId)
                    {
                        Console.WriteLine("team with the id " + teamId + " doesnt exist");
                        continue;
                    }

                    if (teams[teamId - 1].Money < players[playerId - 1].Price)
                    {
                        Console.WriteLine("the team cant afford to buy this player");
                        continue;
                    }
                    if (players[playerId - 1].TeamID != 0)
                    {
                        Console.WriteLine("player already has a team");
                        continue;
                    }

                    players[playerId - 1].TeamID = teamId;
                    teams[teamId - 1].Money -= players[playerId - 1].Price;
                    teams[teamId - 1].PlayersCount++;
                    teams[teamId - 1].Players.Add(players[playerId - 1]);
                    Console.WriteLine("player added to the team succesfully");
                }else if (input[0] == "sell")
                {
                    int teamId = int.Parse(input[2]);
                    int playerId = int.Parse(input[1]);
                    if (players.Count < playerId)
                    {
                        Console.WriteLine("player with the id " + playerId + " doesnt exist");
                        continue;
                    }
                    if (teams.Count < teamId)
                    {
                        Console.WriteLine("team with the id " + teamId + " doesnt exist");
                        continue;
                    }

                    if (players[playerId - 1].TeamID != teamId)
                    {
                        Console.WriteLine("team doesnt have this player");
                        continue;
                    }

                    teams[teamId - 1].Money += players[playerId - 1].Price;
                    players[playerId - 1].TeamID = 0;
                    teams[teamId - 1].PlayersCount--;
                    teams[teamId - 1].Players.Remove(players[playerId - 1]);
                    Console.WriteLine("player sold succesfully");
                }else if (input[0] == "match")
                {
                    int teamId1 = int.Parse(input[1]), teamId2 = int.Parse(input[2]);
                    if (teams.Count < teamId1 || teams.Count < teamId2)
                    {
                        Console.WriteLine("team doesnt exist");
                        continue;
                    }

                    if (teams[teamId1 - 1].PlayersCount < 11 || teams[teamId2 - 1].PlayersCount < 11)
                    {
                        Console.WriteLine("the game can not be held due to loss of the players");
                        continue;
                    }

                    int power1 = 0, power2 = 0;
                    for (int i = 0; i < 11; i++)
                        power1 += teams[teamId1 - 1].Players[i].Finishing + teams[teamId1 - 1].Players[i].Speed;
                    for (int i = 0; i < 11; i++)
                        power2 += teams[teamId2 - 1].Players[i].Defence + teams[teamId2 - 1].Players[i].Speed;

                    if (power1 > power2)
                    {
                        teams[teamId1 - 1].Wins++;
                        teams[teamId1 - 1].Money+=1000;
                        teams[teamId2 - 1].Losses++;
                    }else if (power1 < power2)
                    {
                        teams[teamId2 - 1].Wins++;
                        teams[teamId2 - 1].Money += 1000;
                        teams[teamId1 - 1].Losses++;
                    }
                    else
                    {
                        teams[teamId1 - 1].Ties++;
                        teams[teamId2 - 1].Ties++;
                    }
                }else if (input[0] == "rank")
                {
                    var arr = teams.ToArray();
                    int n = arr.Length;
                    for (int i = 0; i < n - 1; i++)
                    for (int j = 0; j < n - i - 1; j++)
                        if (arr[j].Wins < arr[j + 1].Wins) // note that is is reverse of sort
                        {
                            // swap temp and arr[i] 
                            Team temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }

                    for (int i = 0; i < arr.Length; i++)
                    {
                        Console.WriteLine((i+1).ToString() + ". " + arr[i].Name);
                    }
                }
            }
        }
    }
}
