#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

double calculate_profit(double original_value, double current_value)
{
    return current_value - original_value;
}

double calculate_return(double original_value, double current_value)
{
    double profit = current_value - original_value;
    return (profit / original_value) * 100;
}

int main()
{
    int Investment_number = 0;

    cout << "*****WELCOME TO PORTFOLIO PERFORMANCE ANALYZER*****\n"
        << endl;

    cout << "How many investments are in your portfolio? " << endl;
    cin >> Investment_number;

    if (Investment_number <= 0)
    {
        cout << "Error: insufficient number of investments.";
        return 0;
    }

    vector<string> Investment_name;
    vector<double> original_value;
    vector<double> current_value;

    for (int i = 1; i <= Investment_number; i++)
    {
        string name_i;
        double original_i;
        double current_i;

        cout << "Investment number " << i << endl;

        cout << "Investment name: " << endl;
        cin >> name_i;

        cout << "Original Invested Amount: " << endl;
        cin >> original_i;

        cout << "Current Value: " << endl;
        cin >> current_i;

        Investment_name.push_back(name_i);
        original_value.push_back(original_i);
        current_value.push_back(current_i);
    }

    cout << "\n----- Investment Report -----\n"
        << endl;

    vector<double> profit;
    vector<double> percentage;

    for (int j = 0; j < Investment_number; j++)
    {
        cout << Investment_name[j] << endl;

        double profit_j =
            calculate_profit(original_value[j], current_value[j]);

        cout << "Gain/Loss: $" << profit_j << endl;

        profit.push_back(profit_j);

        double percentage_j =
            calculate_return(original_value[j], current_value[j]);

        cout << "Return: " << percentage_j << "%" << endl;

        percentage.push_back(percentage_j);

        if (profit_j > 0)
        {
            cout << "Performance: Gain" << endl;
        }
        else if (profit_j < 0)
        {
            cout << "Performance: Loss" << endl;
        }
        else
        {
            cout << "Performance: No change" << endl;
        }

        cout << endl;
    }

    int best_index = 0;

    for (int j = 1; j < Investment_number; j++)
    {
        if (percentage[j] > percentage[best_index])
        {
            best_index = j;
        }
    }

    cout << "----- Portfolio Summary -----\n"
        << endl;

    double Total_invested =
        accumulate(original_value.begin(), original_value.end(), 0.0);

    cout << "Total Invested: $" << Total_invested << endl;

    double Total_current =
        accumulate(current_value.begin(), current_value.end(), 0.0);

    cout << "Total current value: $" << Total_current << endl;

    double Total_profit =
        accumulate(profit.begin(), profit.end(), 0.0);

    cout << "Total profit/loss: $" << Total_profit << endl;

    double Total_return =
        (Total_profit / Total_invested) * 100;

    cout << "Total return: " << Total_return << "%" << endl;

    cout << "Best-performing investment: "
        << Investment_name[best_index] << endl;

    return 0;
}