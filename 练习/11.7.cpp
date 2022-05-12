#include<bits/stdc++.h>
using namespace std;


// global file path 
const string kFilePath = "../data/market_price.csv";

// read the csv file to get market data
void readData(const string &filePath, vector<vector<string>> &marketDataTable)
{
	ifstream inFile(filePath);
	string lineStr;
	// read csv line by line
	while (getline(inFile, lineStr))
	{
		stringstream ss(lineStr);
		string str;
		vector<string> lineArray;
		// read one line separated by comma
		while (getline(ss, str, ','))
			lineArray.push_back(str);
		marketDataTable.push_back(lineArray);
	}
}

// calculate vwap value
double calc_vwap(vector<vector<string>> &marketDataTable)
{
	int n = marketDataTable.size() - 1; // skip the first title line
	double total_sum = 0.0;
	int volume_sum = 0;
	for (int i = 1; i <= n; i++)
	{
		// get the price and volume according to table structure
		double high_price = atof(marketDataTable[i][9].c_str());
		double low_price = atof(marketDataTable[i][10].c_str());
		double price = (high_price + low_price) / 2;
		int volume = atoi(marketDataTable[i][11].c_str());
		// compute total sum and volume sum
		total_sum += price * volume;
		volume_sum += volume;
	}

	return total_sum / volume_sum;
}

// calculate twap value
double calc_twap(vector<vector<string>> &marketDataTable)
{
	int n = marketDataTable.size() - 1; // skip the first title line
	double price_sum = 0.0;
	for (int i = 1; i <= n; i++)
	{
		// get the price and volume according to table structure
		double high_price = atof(marketDataTable[i][9].c_str());
		double low_price = atof(marketDataTable[i][10].c_str());
		double price = (high_price + low_price) / 2;
		// compute price sum and time sum
		// here use the 1 min K-line data, so total time is n minutes
		price_sum += price;
	}

	return price_sum / n;
}

int main()
{
	vector<vector<string>> marketDataTable;
	cout << "reading market data" << endl;
	readData(kFilePath, marketDataTable);
	cout << "calculating TWAP and VWAP" << endl;
	cout << "VWAP: " << calc_twap(marketDataTable) << endl;
	cout << "TWAP: " << calc_vwap(marketDataTable) << endl;

	return 0;
}