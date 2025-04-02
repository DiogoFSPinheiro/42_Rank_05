#include "string"
#include "vector"
#include <iostream>
#include <vector>
#include <queue>

int findChar(const std::string &line, char c) {
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] == c) {
            return i;
        }
    }
    return -1; // Character not found
}

// Prints the board for debugging
void printMap(const std::vector<std::string> &B) {
    for (size_t i = 0; i < B.size(); ++i) {
        std::cout << B[i] << std::endl;
    }
}

int countChar(const std::string &line) {
    return line.size();
}


typedef std::pair<int, int> Point;

bool floodFill(std::vector<std::string> &B, int startY, int startX) {
	int N = B.size();
	int M = B[0].size();

	std::vector<std::vector<bool> > visited(N, std::vector<bool>(M, false));
	std::queue<Point> q;

	q.push(Point(startY, startX));
	visited[startY][startX] = true;

	// Possible moves (Up, Down, Left, Right)
	int dRow[] = {-1, 1, 0, 0};
	int dCol[] = {0, 0, -1, 1};

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		int row = p.first;
		int col = p.second;

		// If reached the bottom-right corner
		if (row == N - 1 && col == M - 1)
			return true;

		// Explore all 4 directions
		for (int i = 0; i < 4; i++) {
			int newRow = row + dRow[i];
			int newCol = col + dCol[i];

			if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M && !visited[newRow][newCol] && B[newRow][newCol] == '.')
			{
				
				visited[newRow][newCol] = true;
				q.push(Point(newRow, newCol));
			}
		}
	}
	return false; // No path found
}

std::pair<int,int>	findAssassin(std::vector<std::string> &B)
{
	std::pair<int,int> A(-1,-1);

	for (size_t i = 0; i < B.size(); ++i) {
        for (size_t j = 0; j < B[i].size(); ++j) {
            if (B[i][j] == 'A')
				return {i, j};
        }
    }
	return A;
}



bool solution(std::vector<std::string> &B) {
    std::vector<std::string>::iterator map_it = B.begin();
    int height = B.size();
    int lenght = countChar(*map_it);
    std::string line;

    while (map_it != B.end()) {
        line = *map_it;

        // Right-facing guard '>'
        int view = findChar(line, '>');
        if (view >= 0) {
            while (view <= lenght && line[view] != 'X') {
                line[view] = '0';
                view++;
            }
            *map_it = line;
        }

        // Left-facing guard '<'
        view = findChar(line, '<');
        if (view >= 0) {
            while (0 <= view && line[view] != 'X') {
                line[view] = '0';
                view--;
            }
            *map_it = line;
        }

        ++map_it;
    }

    // Handling downward-facing guard 'v'
    for (int col = 0; col < lenght; ++col) {
        for (int row = 0; row < height; ++row) {
            if (B[row][col] == 'v') {
                int down = row;
                while (down < height && B[down][col] != 'X') {
                    B[down][col] = '0';
                    down++;
                }
            }
        }
    }

    // Handling upward-facing guard '^'
    for (int col = 0; col < lenght; ++col) {
        for (int row = height - 1; row >= 0; --row) {
            if (B[row][col] == '^') {
                int up = row;
                while (up >= 0 && B[up][col] != 'X') {
                    B[up][col] = '0';
                    up--;
                }
            }
        }
    }

    printMap(B);

	std::pair<int, int> A = findAssassin(B);

	if (A != std::make_pair(-1, -1) && floodFill(B, A.first, A.second))
		return true;

	return false;
}



int main()
{
	std::vector<std::string> B = {
		"XA.....>",
		">....X..",
		"....<v.."
	};

	std::cout << (solution(B) ? "true" : "false") << std::endl;

	return 0;
}