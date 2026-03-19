#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombinations(vector<int> &candidates, int target, vector<int> &current, vector<vector<int>> &result, int index)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        if (candidates[i] > target)
            break;
        current.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], current, result, i);
        current.pop_back();
    }
}

int main()
{
    int N, target;
    cout << "Enter number of candidates: ";
    cin >> N;
    vector<int> candidates(N);
    cout << "Enter the candidates: ";
    for (int i = 0; i < N; i++)
    {
        cin >> candidates[i];
    }
    cout << "Enter the target: ";
    cin >> target;

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> current;

    findCombinations(candidates, target, current, result, 0);

    if (result.empty())
    {
        cout << "No combination found" << endl;
    }
    else
    {
        cout << "Combinations are:" << endl;
        for (const auto &combination : result)
        {
            cout << "{ ";
            for (int num : combination)
            {
                cout << num << " ";
            }
            cout << "}" << endl;
        }
    }

    return 0;
}