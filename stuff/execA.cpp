#include <string>
#include <iostream>
#include <vector>

int findChar(const std::string &line, char c, int start) {
    for (int i = start; i < line.size(); ++i) {
        if (line[i] == c) {
            return i;
        }
    }
    return -1; // Character not found
}

int findCharBack(const std::string &line, char c, int start) {
    for (int i = start; i >= 0; --i) {
        if (line[i] == c) {
            return i;
        }
    }
    return -1; // Character not found
}

bool isGuard(char c)
{
	return c == 'v' || c == '^' || c == '>' || c == '<';
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

std::pair<int,int>	findAssassin(std::vector<std::string> &B)
{
	std::pair<int,int> A(-1,-1);

	for (size_t i = 0; i < B.size(); ++i){
		for (size_t j = 0; j < B[i].size(); ++j) {
			if (B[i][j] == 'A')
				return std::make_pair(i, j);
		}
	}
	return A;
}


bool floodFillRecursive(std::vector<std::string> &B, int row, int col, std::vector<std::vector<bool> > &visited) {
	int N = B.size();
	int M = B[0].size();


	if (row < 0 || row >= N || col < 0 || col >= M || visited[row][col])
		return false;

	if (B[row][col] == 'X' || B[row][col] == '0' || isGuard(B[row][col]))
		return false;


	visited[row][col] = true;


	if (row == N - 1 && col == M - 1)
		return true;

	return floodFillRecursive(B, row - 1, col, visited) || // Up
			floodFillRecursive(B, row + 1, col, visited) || // Down
			floodFillRecursive(B, row, col - 1, visited) || // Left
			floodFillRecursive(B, row, col + 1, visited);   // Right
}

bool floodFill(std::vector<std::string> &B, int startY, int startX)
{
	int N = B.size();
	int M = B[0].size();
	std::vector<std::vector<bool> > visited(N, std::vector<bool>(M, false));

	return floodFillRecursive(B, startY, startX, visited);
}




bool solution(std::vector<std::string> &B) {
	std::vector<std::string>::iterator map_it = B.begin();
	int height = B.size();
	int lenght = countChar(*map_it);
	std::string line;

	while (map_it != B.end())
	{
		line = *map_it;
	
		int view = 0;
		while ((view = findChar(line, '>', view)) != -1)
		{
			int pos = view + 1;
			while (pos < lenght && line[pos] != 'X' && !isGuard(line[pos]))
			{
				line[pos] = '0';
				pos++;
			}
			view++;
		}
	
		view = line.length() - 1;
		while ((view = findCharBack(line, '<', view)) != -1)
		{
			int pos = view - 1;
			while (pos >= 0 && line[pos] != 'X' && !isGuard(line[pos]))
			{
				line[pos] = '0';
				pos--;
			}
			view--;
		}
	
		*map_it = line;
		++map_it;
	}
	

	for (int col = 0; col < lenght; ++col)
	{
		for (int row = 0; row < height; ++row)
		{
			if (B[row][col] == 'v')
			{
				int down = row + 1;
				while (down < height && B[down][col] != 'X' && !isGuard(B[down][col]))
				{
					B[down][col] = '0';
					down++;
				}
			}
		}
	}

	for (int col = 0; col < lenght; ++col)
	{
		for (int row = height - 1; row >= 0; --row)
		{
			if (B[row][col] == '^')
			{
				int up = row - 1;
				while (up >= 0 && B[up][col] != 'X' && !isGuard(B[up][col]))
				{
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
	std::vector<std::string> B;
	B.push_back("XA.....v");
	B.push_back(">.>..X..");
	B.push_back("..<..<.>");
	B.push_back("..<..<..");

	std::cout << (solution(B) ? "true" : "false") << std::endl;

	return 0;
}