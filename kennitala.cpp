#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Skilgreinum falli� isLegal, sem skilar �t s�nnu e�a
// �s�nnu eftir �v� hvort a� kennitala s� l�gleg e�a ekki.
bool isLegal (string kennitala) {
    int tiu = kennitala.size();
    // Vi� komumst bara inn � �treikningana ef a� 10 t�lur hafa veri� slegnar inn
    if (tiu == 10){
        // Skilgreinum st�r�ir sem vi� �urfum a� nota � for-lykkju
        int summa = 0;
        int runa = 3;
        char vartala = '0';
        int ivartala = 0;

        // L�tum for-lykkjuna ganga 8 hringi og reikna fyrir eina af
        // fyrstu 8 t�lunum � hverjum hring.
        for (int i = 0; i < 8; i++) {

            // Notum vartala og ivartala til a� breyta gefnum streng yfir � heilt�lur
            vartala = kennitala[i];
            ivartala = (int)vartala - 48;

            summa += ivartala*runa;
            runa = runa -1;

            // Talnarunan sem vi� erum a� vinna me� er 3-2-7-6-5-4-3-2.
            // Vi� l�tum hana byrja � �remur og � lok annarar umfer�ar �
            // lykkjunni, �� h�kkum vi� upp � 7.
            if (runa == 1) {
                runa =7;
            }
        }

        // finnum leifina me� modulus
        int afgangur = summa % 11;

        // Finnum hina eiginlegu vart�lu, h�r sk�r� tekktala
        int tekkTala = 11-afgangur;

        // Ef vi� f�um �t 11, �� eigum vi� a� nota 0 � sta�inn
        if (tekkTala == 11) {
            tekkTala = 0;
        }

        // Ef vi� f�um �t 10, �� �arf a� h�kka ra�t�luna um 1 og reina �t n�ja vart�lu
        if (tekkTala == 10) {
            int temp = 0;
            vartala = kennitala[6];
            ivartala = (int)vartala - 48;
            temp = 10*ivartala;
            vartala = kennitala[7];
            ivartala = (int)vartala - 48;
            temp += ivartala;
            temp++; // H�kka ra�t�luna um 1


            string nytt = static_cast<ostringstream*>( &(ostringstream() << temp) )->str();


            kennitala[6] = nytt[0]; // Set n�ju gildin � ra�t�lunni inn � kennit�luna
            kennitala[7] = nytt[1];
            bool nyKennitala = isLegal(kennitala); // Keyrum forriti� endurkv�mt
            return nyKennitala; //skilum ni�urst��unni �r endurkv�mu keyrslunni � isLegal
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
