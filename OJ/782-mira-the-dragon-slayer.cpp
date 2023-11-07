// 782: Mira - The Dragon Slayer

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int miraHp, dragonHp, miraAtk, dragonAtk, dragonHeal;
    while (cin >> miraHp >> dragonHp >> miraAtk >> dragonAtk >> dragonHeal) {
        if (miraAtk < dragonHp && miraAtk <= dragonHeal) {
            cout << "No" << endl;
        } else {
            while (miraHp > 0 && dragonHp > 0) {
                dragonHp -= miraAtk;
                if (dragonHp <= 0) {
                    cout << "Yes" << endl;
                    break;
                }
                miraHp -= dragonAtk;
                if (miraHp <= 0) {
                    cout << "No" << endl;
                    break;
                }
                dragonHp += dragonHeal;
            }
        }
    }
}