using System;
using System.Collections.Generic;
using System.Linq;

namespace Q9742
{
    class Program
    {
        /// <summary>
        /// A user to store in database
        /// </summary>
        struct User : IComparable<User>
        {
            public string Username { get; set; }
            public string Gender { get; set; }
            public string Age { get; set; }
            public string Id { get; set; }

            public int CompareTo(User other)
            {
                // Compare the string together. It looks like the case matter
                return string.Compare(Id, other.Id, StringComparison.Ordinal);
            }

            /// <summary>
            /// Override this function to make the User printable in Console.WriteLine
            /// </summary>
            /// <returns></returns>
            public override string ToString()
            {
                // Do not use $ because Quera doesn't support it
                return string.Format("{0} {1} {2} {3}", Username, Gender, Age, Id);
            }
        }

        public static void Main(string[] args)
        {
            var users = new SortedSet<User>(); // store the usernames in order to perform binary search later
            int commandCounter = 1; // count the commands to 
            string line;
            while ((line = Console.ReadLine()) != null) // read until EOF
            {
                string[] segments = line.Split(' ');
                if (segments[0][0] == 'A') // Add
                {
                    users.Add(new User
                    {
                        Username = segments[1],
                        Gender = segments[2],
                        Age = segments[3],
                        Id = segments[4],
                    });
                    Console.WriteLine("User {0} added successfully", segments[4]);
                }
                else
                {
                    var temp = new User[users.Count];
                    // Check empty users
                    if (temp.Length == 0)
                    {
                        Console.WriteLine("{0} No user found", commandCounter);
                        commandCounter++;
                    }
                    // Copy sorted list to temp array to enable indexing; I'm not sure if there is any better way to do this
                    users.CopyTo(temp);
                    // Perform binary search to index of first element
                    int index = BinarySearch(temp, new User {Id = segments[1]});
                    int printed = 0;
                    while (index < temp.Length && temp[index].Id.StartsWith(segments[1])) // find all entries that start with search query
                    {
                        if (printed == 10) // do not print more than 10 entries
                            break;
                        Console.WriteLine("{0} {1}", commandCounter, temp[index]); // print the entry
                        index++; // move the cursor in array
                        printed++; // add one to printed to count printed users
                    }

                    if (printed == 0) // if nothing is printed, print this
                        Console.WriteLine("{0} No user found", commandCounter);
                    
                    commandCounter++;
                }
            }
        }
        /// <summary>
        /// Performers binary search and finds the index of first element closest to <see cref="toSearch"/>
        /// </summary>
        /// <param name="ary">The array to search in</param>
        /// <param name="toSearch">The element to search</param>
        /// <returns>The index of nearest element to <see cref="toSearch"/></returns>
        private static int BinarySearch(User[] ary, User toSearch)
        {
            if (ary.Length == 0)
                return 0;

            if (ary[0].CompareTo(toSearch) > 0)
                return 0;
            
            if (ary.Last().CompareTo(toSearch) < 0)
                return ary.Length;

            int lo = 0;
            int hi = ary.Length - 1;

            while (lo <= hi)
            {
                int mid = (hi + lo) / 2;
                if (ary[mid].CompareTo(toSearch) > 0)
                    hi = mid - 1;
                else if (ary[mid].CompareTo(toSearch) < 0)
                    lo = mid + 1;
                else
                    return mid;
            }
            return lo;
        }
    }
}
