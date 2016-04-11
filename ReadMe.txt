Lab 10: Disjoint Set (n x m maze)

Program will ask for number of rows and columns.

Implementation Strategy:
rand() % m*n //generate random number to represent a random cell
rand() % 4   //generate number to represent the walls of the cell and remove that wall
             0 = N, 1 = E, 2 = W, 3 = S

(Disjoint Set)
Create a 1D array with -1 in each element to show no connection
Each array index represents a set, so if 8 becomes connected with 13, store 8 in
the 13th index.

Keep a vertical wall and horizontal wall arrays to track which walls have been removed

Horizontal: wall numbers correspond to the upper cell
Vertical: label east outer walls as already removed as you cannot remove edge walls

for cell i, i - n = N
            i = S
            i - 1 = W
            i = E

If the two cells are already connected, do not remove the wall.

Done when all cells are connected to each other (there is one -1 (root) remaining
in the disjoing set array)
