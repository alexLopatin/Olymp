
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int GetMonth(string month) {
    if(strcmp(month.c_str(), "Jan") == 0)
        return 1;
    if(strcmp(month.c_str(), "Feb") == 0)
        return 2;
    if(strcmp(month.c_str(), "Mar") == 0)
        return 3;
    if(strcmp(month.c_str(), "Apr") == 0)
        return 4;
    if(strcmp(month.c_str(), "May") == 0)
        return 5;
    if(strcmp(month.c_str(), "Jun") == 0)
        return 6;
    if(strcmp(month.c_str(), "Jul") == 0)
        return 7;
    if(strcmp(month.c_str(), "Aug") == 0)
        return 8;
    if(strcmp(month.c_str(), "Sept") == 0)
        return 9;
    if(strcmp(month.c_str(), "Oct") == 0)
        return 10;
    if(strcmp(month.c_str(), "Nov") == 0)
        return 11;
    if(strcmp(month.c_str(), "Dec") == 0)
        return 12;
    return 0;
}

string ToStr(int date) {
    string res;

    int month = date / 100;
    int day = date % 100;
    switch(month) {
        case 1:
            res += "Jan";
            break;
        case 2:
            res += "Feb";
            break;
        case 3:
            res += "Mar";
            break;
        case 4:
            res += "Apr";
            break;
        case 5:
            res += "May";
            break;
        case 6:
            res += "Jun";
            break;
        case 7:
            res += "Jul";
            break;
        case 8:
            res += "Aug";
            break;
        case 9:
            res += "Sept";
            break;
        case 10:
            res += "Oct";
            break;
        case 11:
            res += "Nov";
            break;
        case 12:
            res += "Dec";
            break;
    }
    res += " ";
    res += std::to_string(day);
    if(day % 20 == 1)
        res += "st";
    else
    if(day % 20 == 2)
        res += "nd";
    else if(day % 20 == 3)
        res += "rd";
    else
        res += "th";
    return res;
}

int GetDay(string day) {
    day = day.substr(0, day.length() - 2);
    return std::stoi(day);
}

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        vector<int> dates;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            string month, day;
            cin >> month >> day;
            dates.push_back(GetDay(day) + 100*GetMonth(month));
        }
        sort(dates.begin(), dates.end());
        string month, day;
        cin >> month >> day;
        int date = GetDay(day) + 100*GetMonth(month);
        bool find = 0;
        for(int j = 0; j < n; j++) {
            if(dates[j] > date) {
                cout << "Case #" << i + 1 << ": " <<  ToStr( dates[j] )<< endl;
                find = 1;
                break;
            }
        }
        if(!find)
            cout << "Case #" << i + 1 << ": See you next year"<< endl;
    }
}