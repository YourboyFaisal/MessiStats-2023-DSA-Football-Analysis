# MessiStats 2023: DSA Football Analysis

The  DSA  project  as  the  topic  name  suggests  works  around  Messi’s  career  goals till  2023.  It focuses on  analyzing  Lionel  Messi's  illustrious  football  career.  The  project  aims  to  explore  and understand various DSA concepts such as Linked List, Binary Search Tree and Hash maps by applying them  to  real-world  data  related  to  Messi's  performances,  achievements,  and  statistics. The project systematically stores more than 10 years of collected data in a CSV file prior to parsing.
Features:

The main function will mainly consist of these functions:
1. Print all of Messi's club goals with details such as Competition, Date, Venue, Club For, Club Against, Time, Assist, etc upon parsing the file. This is initially done into a linked list, which is then changed to other data structures for later functions.
2. Search a team that Messi has scored against (i.e: Arsenal FC, Real Madrid, Manchester United, etc). Upon entering the name of the team, it would tell you the number of goals scored against that team. This is done after converting the linked list to a Binary Search Tree for the teams only to consume less memory, and then performing a search on that tree.
3. Search a player to get his records on assists to Messi (i.e: Neymar, Andres Iniesta). Upon entering the name of the player, it would tell you the number of assists given to Messi. This is done after making a Hash Table from the data and searching and inserting with O(1) time complexity to increase speed.
4. Print the goal records with respect to time of goal scored (i.e: Enter the range of time (1-10, 10-20) and get the records). This has also been done using a hash table that stores records for each portion of time.
5. Exit the program.

Dataset Available on Kaggle: https://www.kaggle.com/datasets/azminetoushikwasi/-lionel-messi-all-club-goals/discussion
