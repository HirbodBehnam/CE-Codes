#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#define MAX_COMMAND 10000
#define MAX_NAME 1000

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct u {
    char username[MAX_NAME];
    struct u *introducer;
    int balance;
    int referrers;
} User;

/**
 * The result of find_user
 */
typedef struct uf {
    /**
     * Is null if users is not found
     */
    User *user;
    int level;
    int index;
} UserFound;

typedef struct l {
    /**
     * Number of users in this level
     */
    int number_of_users;
    /**
     * Array of users, each point to a users on heap
     */
    User **users;
} Level;

typedef struct t {
    int number_of_levels;
    int total_users;
    /**
     * Array of levels
     */
    Level *levels;
} Table;

/**
 * Checks if a string begins with another string
 * @param str The string to check if it begins
 * @param pre The string to check if the str starts with
 * @return True if str begins with pre, otherwise false
 */
bool begins_with(const char *str, const char *pre) {
    return strncmp(pre, str, strlen(pre)) == 0;
}

/**
 * Creates a users in heap
 * @param username Username
 * @param balance Initial balance
 * @param introducer Who is the introducer
 * @return The users created
 */
User *create_user(const char *username, int balance, User *introducer) {
    User *res = malloc(sizeof(User));
    res->referrers = 0;
    res->balance = balance;
    res->introducer = introducer;
    strcpy(res->username, username);
    return res;
}

/**
 * Finds a users by it's username
 * @param username The username to check
 * @return The pointer to users if the users is found; Otherwise NULL
 */
UserFound find_user(const char *username, const Table *table) {
    UserFound user;
    user.user = NULL;
    if (table->total_users == 0) // will this happen? idk
        return user;
    // check the lead
    if (strcmp(table->levels[0].users[0]->username, username) == 0) {
        user.user = table->levels[0].users[0];
        user.index = user.level = 0;
    }
    // check other ppl
    for (int i = 1; i < table->number_of_levels; i++)
        for (int j = 0; j < table->levels[i].number_of_users; j++)
            if (strcmp(table->levels[i].users[j]->username, username) == 0) {
                user.user = table->levels[i].users[j];
                user.level = i;
                user.index = j;
                return user;
            }
    return user; // no users found
}

int main() {
    int benjamin_money = 0;
    Table table;
    table.total_users = table.number_of_levels = 0;
    table.levels = NULL;
    char *command = malloc(MAX_COMMAND * sizeof(char));
    while (1) {
        fgets(command, MAX_COMMAND, stdin);
        command[strlen(command) - 1] = 0; // remove \n
        // check commands
        if (begins_with(command, "En")) // end
            return 0;
        if (begins_with(command, "Create_a_table_for")) {
            if (table.levels == NULL) { // check the balance
                int init_money;
                char username[MAX_NAME];
                sscanf(command, "%*s %s %*s %d", username, &init_money);
                if (init_money < 5000) {
                    puts("Money is not enough");
                } else {
                    table.total_users = table.number_of_levels = 1; // add the lead
                    table.levels = malloc(sizeof(Level)); // add one level
                    table.levels[0].number_of_users = 1;
                    table.levels[0].users = malloc(sizeof(User *)); // add one users
                    table.levels[0].users[0] = create_user(username, init_money - 5000, NULL); // add the users
                    benjamin_money = 5000;
                    puts("You now own a table");
                }
            } else {
                puts("We already have a founder");
            }
            continue;
        }
        if (begins_with(command, "Invitation_request_from")) {
            // get data
            char newName[MAX_NAME], fromName[MAX_NAME];
            int money;
            sscanf(command, "%*s %s %*s %s %*s %d", fromName, newName, &money);
            // check if the user exists
            if (find_user(newName, &table).user != NULL) {
                puts("Username already taken");
                continue;
            }
            // find inter
            UserFound introducer = find_user(fromName, &table);
            introducer.user->referrers++;
            // add money to people
            table.levels[0].users[0]->balance += money / 10; // table creator: 10%
            benjamin_money += money * 15 / 100; // benjamin: 15%
            introducer.user->balance += money / 20; // introducer: 5%
            // create user
            User *user = create_user(newName, money / 5, introducer.user);
            // find a level with empty space
            int level = introducer.level + 1;
            while (level < table.number_of_levels && level * level == table.levels[level].number_of_users)
                level++;
            // add the user to that level
            if (table.number_of_levels == level) {
                table.number_of_levels++;
                table.levels = realloc(table.levels, table.number_of_levels * sizeof(Level));
                table.levels[table.number_of_levels - 1].number_of_users = 1;
                table.levels[table.number_of_levels - 1].users = malloc(1 * sizeof(User *));
                table.levels[table.number_of_levels - 1].users[0] = user;
            } else {
                table.levels[level].number_of_users++;
                table.levels[level].users = realloc(table.levels[level].users,
                                                    table.levels[level].number_of_users * sizeof(User *));
                table.levels[level].users[table.levels[level].number_of_users - 1] = user;
            }
            // add money to upper tables
            money /= 2;
            money /= level; // now money is the total money for each level
            for (int i = 0; i < level; i++) {
                const int users_count = table.levels[i].number_of_users;
                for (int j = 0; j < users_count; j++)
                    table.levels[i].users[j]->balance += money / users_count;
            }
            // update table
            table.total_users++;
            printf("User added successfully in level %d\n", level);
            // check if referrer needs promote
            if (introducer.user->referrers == 5) {
                level = introducer.level - 1;
                introducer.user->referrers = 0;
                if (table.levels[level].number_of_users == level * level) { // full level!
                    // check if everything is equal
                    bool reffs_are_equal = true;
                    User *option = table.levels[level].users[0];
                    int index = 0;
                    for (int i = 0; i < table.levels[level].number_of_users; i++) {
                        if (table.levels[level].users[i]->referrers != option->referrers)
                            reffs_are_equal = false;
                        if (option->referrers > table.levels[level].users[i]->referrers) {
                            option = table.levels[level].users[i];
                            index = i;
                        }
                    }
                    if (reffs_are_equal) { // check money
                        for (int i = 0; i < table.levels[level].number_of_users; i++)
                            if (option->balance > table.levels[level].users[i]->balance) {
                                option = table.levels[level].users[i];
                                index = i;
                            }
                    }
                    // swap places
                    table.levels[level].users[index] = introducer.user;
                    table.levels[level + 1].users[introducer.index] = option;
                } else { // we have space
                    // add this user to upper level
                    table.levels[level].number_of_users++;
                    table.levels[level].users = realloc(table.levels[level].users,
                                                        table.levels[level].number_of_users * sizeof(User *));
                    table.levels[level].users[table.levels[level].number_of_users - 1] = introducer.user;
                    // move other users in lower level
                    level++;
                    memmove(table.levels[level].users + introducer.index,
                            table.levels[level].users + introducer.index + 1,
                            (table.levels[level].number_of_users - introducer.index + 1) * sizeof(User *));
                    table.levels[level].number_of_users--;
                }
            }
            continue;
        }
        if (begins_with(command, "Join_request_for")) {
            // get data
            char newName[MAX_NAME];
            int money;
            sscanf(command, "%*s %s %*s %d", newName, &money);
            // check if the user exists
            if (find_user(newName, &table).user != NULL) {
                puts("Username already taken");
                continue;
            }
            // add money to people
            table.levels[0].users[0]->balance += money / 10; // table creator: 10%
            benjamin_money += money / 4; // benjamin: 25%
            // create user
            User *user = create_user(newName, money * 15 / 100, NULL);
            // add the user to last
            int level = table.number_of_levels - 1;
            if (level * level == table.levels[level].number_of_users || level == 0) { // add a new level
                level++;
                table.number_of_levels++;
                table.levels = realloc(table.levels, table.number_of_levels * sizeof(Level));
                table.levels[table.number_of_levels - 1].number_of_users = 1;
                table.levels[table.number_of_levels - 1].users = malloc(1 * sizeof(User *));
                table.levels[table.number_of_levels - 1].users[0] = user;
            } else { // add to current level
                table.levels[level].number_of_users++;
                table.levels[level].users = realloc(table.levels[level].users,
                                                    table.levels[level].number_of_users * sizeof(User *));
                table.levels[level].users[table.levels[level].number_of_users - 1] = user;
            }
            // add money to upper tables
            money /= 2;
            money /= level; // now money is the total money for each level
            for (int i = 0; i < level; i++) {
                const int users_count = table.levels[i].number_of_users;
                for (int j = 0; j < users_count; j++)
                    table.levels[i].users[j]->balance += money / users_count;
            }
            // update table
            table.total_users++;
            printf("User added successfully in level %d\n", level);
            continue;
        }
        if (begins_with(command, "Number_of_levels")) {
            printf("%d\n", table.number_of_levels);
            continue;
        }
        if (begins_with(command, "Number_of_users_in_level")) {
            int level;
            sscanf(command, "%*s %d", &level);
            if (level >= table.number_of_levels)
                puts("No_such_level_found");
            else
                printf("%d\n", table.levels[level].number_of_users);
            continue;
        }
        if (begins_with(command, "Number_of_users")) {
            printf("%d\n", table.total_users);
            continue;
        }
        if (begins_with(command, "Introducer_of")) {
            char name[MAX_NAME];
            sscanf(command, "%*s %s", name);
            UserFound user = find_user(name, &table);
            if (user.user == NULL)
                puts("No_such_user_found");
            else if (user.user->introducer == NULL)
                puts("No_introducer");
            else
                puts(user.user->introducer->username);
            continue;
        }
        if (begins_with(command, "Friends_of")) {
            char name[MAX_NAME];
            sscanf(command, "%*s %s", name);
            UserFound user = find_user(name, &table);
            if (user.user == NULL)
                puts("No_such_user_found");
            else {
                Level level = table.levels[user.level];
                if (level.number_of_users == 1)
                    puts("No_friend");
                else if (user.index == 0)
                    puts(level.users[user.index + 1]->username);
                else if (user.index == level.number_of_users - 1)
                    puts(level.users[user.index - 1]->username);
                else {
                    // left user first
                    puts(level.users[user.index - 1]->username);
                    puts(level.users[user.index + 1]->username);
                }
            }
            continue;
        }
        if (begins_with(command, "Credit_of")) {
            char name[MAX_NAME];
            sscanf(command, "%*s %s", name);
            UserFound user = find_user(name, &table);
            if (user.user == NULL)
                puts("No_such_user_found");
            else
                printf("%d\n", user.user->balance);
            continue;
        }
        if (begins_with(command, "Users_on_the_same_level_with")) {
            char name[MAX_NAME];
            sscanf(command, "%*s %s", name);
            UserFound user = find_user(name, &table);
            if (user.user == NULL)
                puts("No_such_user_found");
            else {
                Level level = table.levels[user.level];
                if (level.number_of_users == 1)
                    puts("He_is_all_by_himself");
                else {
                    for (int i = 0; i < level.number_of_users; i++)
                        if (strcmp(level.users[i]->username, name) != 0)
                            printf("%s ", level.users[i]->username);

                    putchar('\n');
                }
            }
            continue;
        }
        if (begins_with(command, "How_much_have_we_made_yet")) {
            printf("%d\n", benjamin_money);
            continue;
        }
    }
}