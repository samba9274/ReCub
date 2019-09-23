# ReCub
Code to calculate unique permutations of a 3x3x3 Rubik's Cube.


Here is a code I made that calculates unique permutations of a 3x3x3 cube.
The program starts with a solved cube and makes one move at a time and checks if the new found permutation of cube has already occured, and if not, it saves it in a file to be checked after each move.
Permutation stored in file is stored as a concatenated string of moves performed on cube and resultant cube permutation.

# Factors to check if the permutation is unique
1. If the cube permutation is obtained before in the file.
    check_repeat() is function which checks if current cube permutation is already available in perm.dat file.
2. If the every move made to get current permutation was done in another orientation of cube, is it still unique.
    check_rotate() is function which checks if moves made on solved cube to obtain current cube permutation were done having some other cube orientation obtains another cube permutation; this newly obtained permutation is then checked in perm.dat file.
3. If all the moves were mirrored.
    check_mirror() is function performs moves made to get current permutation in a mirrored way to obtain new permutation. This new permutation is checked with perm.dat file and also checked through check_rotate() function to get all possible orientations.
    Here mirroring moves means :
      Right -> Left
      Up -> UpInverted
      Front -> FrontInverted and so on.
      
# Saving results
When a permutation passes all the checks and is unique in above mentioned ways, it is stored in 'perm.dat' named file.

# Notes
In the Code, MaxMoves indicates till how many moves does the program has to check the permutations. I've set it to 20 because it was previously observed as all permutations beyond 20 moves repeat themselves.

While storing results, I've used Alphabets A - L to determine cube moves.
A : Up
B : UpInverted
C : Down
D : DownInverted
E : Left
F : LeftInverted
G : Right
H : RightInverted
I : Front
J : FrontInverted
K : Back
L : BackInverted

In perm.dat,
W : White
R : Red
B : Blue
O : Orange
G : Green
Y : Yellow

This is first time I've wrote such a big code so please ignore wrong naming conventions, wrong coding conventions. Please comment for how to improve the same. Thank you.
