# 42-BSQ, by Hélios Daher and Maxime Rochedy

Welcome to our **BSQ** (**Biggest Square**) project implementation, completed during the **École 42 piscine**. This project is one of the toughest and least completed challenges in the piscine, as it is optional, lasts only three days, and falls within the final days of the piscine, days that are often devoted to final exam preparation or completing other core projects.

Here, you'll find a carefully crafted version that was evaluated by three different students, as well as the **Moulinette** correction tool, achieving a perfect score of **100/100**. While every effort was made to ensure the code is bug-free, errors may still exist. Your feedback is highly appreciated!

## About the Project

The **BSQ** project is all about developing an efficient algorithm to find the largest possible square that can be placed on a given map filled with obstacles. Each map is represented by characters, with some cells designated as obstacles and others as empty spaces. Our program reads a file containing this grid of characters, processes the data, and identifies the largest possible square that can be formed in the unobstructed regions of the map. The final result shows this largest square visually, replacing the corresponding cells with a character that marks the filled area.

The **BSQ** project is a great way to develop proficiency in **dynamic programming**, file handling, and optimized algorithm design, all within an intense time constraint that mimics real-life problem-solving scenarios.

## Our Solution

To solve the **BSQ** problem, we designed an approach that transforms the input map into a numerical representation that can be efficiently processed to locate the largest possible square of empty spaces.

Here's a detailed breakdown of our approach:

1. We began by converting the character map into an **integer map**. In this new representation:

   - Empty spaces were represented by **0**.
   - Obstacles were represented by **-1**.

2. Starting from the **top-left** corner, we iteratively calculated the values for each empty cell based on its neighboring cells:

   - For each empty cell, we updated its value based on the **minimum value** among three neighboring cells: the cell to the **left**, the cell **above**, and the cell **diagonally up-left**.
   - Specifically, if the current cell is empty, we set its value to **min(left, top, top-left) + 1**. This method effectively builds up the maximum side length of any square that can end at that particular cell.

3. As we filled the integer map, the **highest value** in the entire map represented the size of the largest possible square, with that value being the length of the side. The position of this value also indicated the **bottom-right corner** of the largest square.
   _PS: If there were multiple cells with the same highest value, we selected the one that was **closest to the top** and then **closest to the left**, ensuring a consistent solution._

4. Once we identified the largest value and its position, we determined the **top-left corner** of the corresponding square. We then replaced the appropriate cells in the original character map with the designated **filled character** to visually display the largest square.

This approach ensured that our solution was both **efficient** and **clear**, capable of handling larger maps within the time constraints of the project.

## Getting Started

To use our **BSQ** implementation, simply clone the repository and compile the project using `make`.

```bash
git clone https://github.com/mrochedy/42-BSQ.git
cd 42-BSQ
make
```

After compilation, you can run the program by passing a map file as an argument:

```bash
./bsq [map_file]
```

A `maps` folder is present at the root of the repository and contains several maps to test the program with, including some invalid maps, for testing purposes.

## Contributing

We welcome any feedback, suggestions, or contributions! If you find this repository useful, please feel free to ⭐️ **star** ⭐️ the project to support its visibility. Contributions are welcome through pull requests, especially if you have ideas for optimization or additional features.

Please respect École 42’s policies on collaboration and plagiarism. While this repository is shared for **educational purposes**, copying it for submission is against the school's guidelines. We encourage you to learn from it, understand the logic, and try implementing your own solution to the **BSQ** problem.

Thank you for visiting and happy coding!
