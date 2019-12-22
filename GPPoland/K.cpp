#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct frog{
    int experation;
    int skill;
}frog;

bool operator<(const frog lhs, const frog rhs){
    return lhs.skill < rhs.skill;
}

int main(){
    int n;
    cin >> n;
    vector<int> frogSkill;
    vector<int> frogRadius;
    for(int i = 0; i < n; i++) {
        int r, s;
        cin >> r >> s;
        frogSkill.push_back(s);
        frogRadius.push_back(r);
    }
    vector<frog> skillFrog;
    int skill = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < skillFrog.size(); j++) {
            if(skillFrog[j].experation < i)
                skillFrog.erase(skillFrog.begin() + j);
        }
        skillFrog.push_back(frog{i + frogRadius[i], frogSkill[i]});
        sort(skillFrog.begin(), skillFrog.end());
        if(skillFrog.size() >= 3){
            int curSkill = skillFrog[skillFrog.size() - 1].skill +skillFrog[skillFrog.size() - 2].skill + skillFrog[skillFrog.size() - 3].skill;
            if(skill < curSkill) {
                skill = curSkill;
            }
        }
    }
    cout << skill << endl;
    return 0;
}