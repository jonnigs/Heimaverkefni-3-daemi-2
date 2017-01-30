#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Skilgreinum fallið isLegal, sem skilar út sönnu eða
// ósönnu eftir því hvort að kennitala sé lögleg eða ekki.
bool isLegal (string kennitala)
{
    int tiu = kennitala.size();
    // Við komumst bara inn í útreikningana ef að 10 tölur hafa verið slegnar inn
    if (tiu == 10)
    {
        // Skilgreinum stærðir sem við þurfum að nota í for-lykkju
        int summa = 0;
        int runa = 3;
        char vartala = '0';
        int ivartala = 0;

        // Látum for-lykkjuna ganga 8 hringi og reikna fyrir eina af
        // fyrstu 8 tölunum í hverjum hring.
        for (int i = 0; i < 8; i++)
        {

            // Notum vartala og ivartala til að breyta gefnum streng yfir í heiltölur
            vartala = kennitala[i];
            ivartala = (int)vartala - 48;

            summa += ivartala*runa;
            runa = runa -1;

            // Talnarunan sem við erum að vinna með er 3-2-7-6-5-4-3-2.
            // Við létum hana byrja í þremur og í lok annarar umferðar í
            // lykkjunni, þá hækkum við upp í 7.
            if (runa == 1)
            {
                runa =7;
            }
        }

        // finnum leifina með modulus
        int afgangur = summa % 11;

        // Finnum hina eiginlegu vartölu, hér skýrð tekktala
        int tekkTala = 11-afgangur;

        // Ef við fáum út 11, þá eigum við að nota 0 í staðinn
        if (tekkTala == 11)
        {
            tekkTala = 0;
        }

        // Ef við fáum út 10, þá þarf að hækka raðtöluna um 1 og reina út nýja vartölu,
        // sem gerir kennitöluna sem var slegin inn ekki löglega.

        if (tekkTala == 10)
        {
            return false;
        }
        vartala = kennitala[8];
        ivartala = (int)vartala - 48;
        if (ivartala == tekkTala)
        {
            if (kennitala[9] == '8' || kennitala[9] == '9' || kennitala[9] == '0' )
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string kennit;
    cout << "Sladu inn 10 stafa kennitolu: " << endl;
    cin >> kennit;
    bool nidurstada = isLegal(kennit);
    if (nidurstada == true)
    {
        cout << "Logleg kennitala!";
    }
    else
    {
        cout << "Ekki logleg kennitala";
    }
    return 0;
}
