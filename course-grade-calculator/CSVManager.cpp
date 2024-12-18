#include "CSVManager.h"

vector<vector<string>> CSVManager::readCSV(const string& filename)
{
    ifstream file(filename);
    vector<vector<string>> data;
    string line;

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return data;
    }

    while (getline(file, line))
    {
        vector<string> row;
        string cell;
        stringstream ss(line);

        while (getline(ss, cell, ','))
            row.push_back(cell);

        data.push_back(row);
    }

    file.close();
    return data;
}

void CSVManager::modifyData(vector<vector<string>>& csvData, unsigned int row, unsigned int col, string data)
{
    if (!csvData.empty() && csvData.size() > 1 && csvData[row].size() > 1)
        csvData[row][col] = data;
}

void CSVManager::writeCSV(const string& filename, const vector<vector<string>>& data)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    for (const auto& row : data)
    {
        for (int i = 0; i < row.size(); ++i)
        {
            file << row[i];
            if (i != row.size() - 1)
                file << ",";
        }
        file << "\n";
    }

    file.close();
}

void CSVManager::displayCSV(const vector<vector<string>>& data)
{
    for (const auto& row : data)
    {
        for (const auto& cell : row)
            cout << cell << " ";
        cout << endl;
    }
}