#include <iostream>

using namespace std;

bool isLegal (string kennitala) {
    int tiu = kennitala.size();
    if (tiu == 10){
        int summa = 0;
        int runa = 3;
        char vartala = '0';
        int ivartala = 0;
        for (int i = 0; i < 8; i++) {
            vartala = kennitala[i];
            ivartala = (int)vartala - 48;
            summa += ivartala*runa;
            runa = runa -1;
            if (runa == 1) {
                runa =7;
            }
        }
        int afgangur = summa % 11;
        int tekkTala = 11-afgangur;
        if (tekkTala == 11) {
            tekkTala = 0;
        }
        vartala = kennitala[8];
        ivartala = (int)vartala - 48;
        if (ivartala == tekkTala){
            if (kennitala[9] == '8' || kennitala[9] == '9' || kennitala[9] == '0' ) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string kennit;
    cout << "Sladu inn 10 stafa kennitolu: " << endl;
    cin >> kennit;
    bool nidurstada = isLegal(kennit);
    if (nidurstada == true) {
        cout << "Logleg kennitala!";
    }
    else {
        cout << "Ekki logleg kennitala";
    }
    return 0;

}
