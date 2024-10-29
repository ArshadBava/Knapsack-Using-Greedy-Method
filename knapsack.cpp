#include <bits/stdc++.h>
using namespace std;

struct Item {
	int profit, weight;
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& arr, int N)
{
	sort(arr.begin(), arr.end(), cmp);

	double finalvalue = 0.0;

	for (int i = 0; i < N; i++) {
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}
		else {
			finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
			break;
		}
	}

	return finalvalue;
}

int main()
{
	int N, W;

	cout << "Enter the number of items: ";
	cin >> N;

	vector<Item> arr;  

	for (int i = 0; i < N; i++) {
		int profit, weight;
		cout << "Enter profit and weight for item " << i + 1 << ": ";
		cin >> profit >> weight;
		arr.push_back(Item(profit, weight));
	}

	cout << "Enter the capacity of the knapsack: ";
	cin >> W;

	cout << "Maximum profit: " << fractionalKnapsack(W, arr, N) << endl;

	return 0;
}


