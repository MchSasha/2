
#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector <int>& index, vector <int>& mas, int first, int last);
void dfs(int& counter, vector <int>& max, const int& k_room, vector<bool>& visited, vector<vector <int>>& inf_doors, int rooms, int doors);
int main()
{
	int rooms = 5;  int doors = 6;
	int counter = 0;
	vector <vector <int>> inf_doors{ {1, 2, 10 }, {1, 2, 5 }, {2, 3, 7 }, {3, 4, 5 }, {2, 4, 10 } , {5, 1, 7} };
	vector <bool> visited(rooms);
	vector <int> max{};
	dfs(counter, max, 1, visited, inf_doors, rooms, doors);
	if (!visited[rooms - 1]) {
		cout << ":(";
		return 0;
	}

	if (counter > max.size()) {
		cout << ":)";
		return 0;
	}
	else {
		int sum = 0;
		for (int i : max)
		{
			sum += i;
		}
		cout << sum;
	}
	}

void dfs(int& counter, vector <int>& max, const int& k_room, vector<bool>& visited, vector<vector <int>>& inf_doors, int rooms, int doors)
{
	vector <int> weight_of_certain_door{};
	vector <int> index{};
	visited[k_room-1] = true;
	if (k_room != rooms) {
		for (int x = 0; x < doors; x++){
			if (inf_doors[x][0] == k_room) {
				weight_of_certain_door.push_back(inf_doors[x][2]);
				index.push_back(inf_doors[x][1]);
				inf_doors[x] = { 0, 0, 0 };
			}
		}
		if (weight_of_certain_door.size() == 0)
			return;


		if (weight_of_certain_door.size() == 2) 
			if (weight_of_certain_door[0] > weight_of_certain_door[1]) {
				swap(weight_of_certain_door[0], weight_of_certain_door[1]);
				swap(index[0], index[1]);
			}

		
		if (weight_of_certain_door.size() > 2)
			quicksort(index, weight_of_certain_door, 0, weight_of_certain_door.size() - 1);

		int max_weight = weight_of_certain_door[weight_of_certain_door.size() - 1];
		max.push_back(max_weight);
		int next_room = index[index.size() - 1];
		counter++;
		if (counter < doors) {
			if (!visited[next_room - 1])
				dfs(counter, max, next_room, visited, inf_doors, rooms, doors);
		}
	} 
}
void quicksort(vector <int>& index, vector <int>& mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; //вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) //перестановка элементов
		{
			swap(mas[f], mas[l]);
			swap(index[f], index[l]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(index, mas, first, l);
	if (f < last) quicksort(index, mas, f, last);
}
/*
	for (int j : inf_doors[k])
	{
		if (!visited[j - 1])
			dfs(j - 1, visited, inf_doors);
	}*/



