using System;
using System.Collections.Generic;

namespace Q660
{
    class Program
    {
        private class Person
        {
            public int InitMoney;
            public int NowMoney;
        }
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var people = new Dictionary<string, Person>(n);
            for (int i = 0; i < n; i++)
            {
                people.Add(Console.ReadLine(), new Person());
            }
            for (int i = 0; i < n; i++)
            {
                Person p = people[Console.ReadLine()];
                string[] line = Console.ReadLine().Split(' ');
                p.InitMoney = int.Parse(line[0]);
                int toGiftCount = int.Parse(line[1]);
                if (toGiftCount == 0)
                {
                    p.NowMoney += p.InitMoney;
                    continue;
                }
                int toGift = p.InitMoney / toGiftCount;
                p.NowMoney += p.InitMoney % toGiftCount;
                for (int j = 0; j < toGiftCount; j++)
                    people[Console.ReadLine()].NowMoney += toGift;
            }
            foreach (var p in people)
            {
                Console.Write(p.Key);
                Console.Write(" ");
                Console.WriteLine(p.Value.NowMoney - p.Value.InitMoney);
            }
        }
    }
}
