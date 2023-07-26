# Combination Finder Algorithm
[![jpn](https://img.shields.io/badge/lang-jpn-red.svg)](https://github.com/renm10/CombFinder/blob/main/README-jp.md)

This is an algorithm made from scratch that lists all possible patterns given a candidate list of numbers that add to a certain sum.

## Example
[1, 2, 3]   Sum = 5  
Output: [1,1,1,1,1]  [2,1,1,1]  [1,2,1,1]  [3,1,1]  [1,1,2,1]  
[2,2,1]  [1,3,1]  [1,1,1,2]  [2,1,2] [1,2,2] [3,2]  [1,1,3]  [2,3]

## How to use
1. Edit **LINE 2** of the numberselect.txt file and enter the candidate numbers separated by a space.
Ex. 9 12 4 3

2. Edit **LINE 4** of the same file and enter the sum that the candiates may add to.

3. Save the file

4. Compile 
    ```
    g++ main.cpp
    ```
5. Run
    ```
    ./a.out //For Unix
    ./a.exe //For Windows
    ```

## TODO
- Potentially check if the user did not enter two of the same numbers in the txt file. 




