#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <sstream>
using namespace std;

int pow(int x,int k,int n)
{
    int section(1) ;
        while(k>0)
        {
            if (k%2!=0)
            {
                section =(section*x)%n ;
            }
            else
            {
                ;
            }
            x = (x*x)%n ;
            k=k/2 ;
        }
    return section ;
}
int tailleDunNombre(int n)
{
    stringstream ss ;
    ss << n;
    string nstr = ss.str();
    int taille(nstr.size()) ;
    return taille ;
}

string miseEnForme (string chaine,int tailleN)
{
    int taille(chaine.size()) ;
    while (taille<tailleN)
    {
        chaine = "0" + chaine ;
        taille=chaine.size() ;
    }
    return chaine ;
}

string IntToChaine (int tableau[], int i)
{
    stringstream ss ;
    ss << tableau[i];
    string chaine = ss.str();
    return chaine ;
}

string intToStr(int tableau[], int tailleTable,int tailleN)
{
    string message, transcrit ;
    for (int i(0); i<tailleTable; i++)
    {
        transcrit = IntToChaine(tableau,i) ;
        transcrit = miseEnForme(transcrit,tailleN) ;
        message+=transcrit ;
    }
    return message ;
}

string conversionEnNombreStr(string ChaineAConvertir)
{
    char ConversionLetchif[37] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    string messageEnNombre, ConversionRangCar[37] = { "00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39" };
    int y (0);
    for(int i(0); i<ChaineAConvertir.size(); i++)
    {
        y=0 ;
        while (ChaineAConvertir[i] != ConversionLetchif[y])
        {
            y += 1;
        }
        messageEnNombre += ConversionRangCar[y] ;
    }
    return messageEnNombre ;
}

void encryption()
{
    int n, e;
    cout << "Saisir n :" << endl ;
    cin >> n ;
    cout << "Saisir e :" << endl ;
    cin >> e ;
    cout << " " << endl ;
    int tailleN(tailleDunNombre(n)) ;
    cin.ignore() ;
    system("cls");

    string messageAcode ;
    cout << "Message a coder : " ;
    getline(cin, messageAcode) ;
    string messageAcrypter = conversionEnNombreStr(messageAcode);

    int const SizeTable((messageAcrypter.size())/(tailleN-1)) ;
    int y(0);
    int tableauTranche[SizeTable] ;
    for (int i(0); i<messageAcrypter.size()/(tailleN-2); i+=tailleN-1)
    {
        tableauTranche[y] = atoi(messageAcrypter.substr(i,tailleN-1).c_str()) ;
        y++ ;
    }

    int tableauCrypte[SizeTable] ;
    for (int i(0); i<SizeTable; i++)
    {
       tableauCrypte[i]=pow(tableauTranche[i],e,n) ;
    }
    string stringFinal(intToStr(tableauCrypte,SizeTable,tailleN));

    cout << " " << endl ;
    cout << "Le message code est : " << endl ;
    cout << stringFinal << endl ;
}

void decodage()
{
    int p(11),q(17),d(23),e(7),n,tailleN ;
    cout << "Saisir p :" << endl ;
    cin >> p ;
    cout << "Saisir q :" << endl ;
    cin >> q ;
    cout << "Saisir d :" << endl ;
    cin >> d ;

    n=q*p ;
    tailleN = tailleDunNombre(n) ;
    system("cls") ;

    string messageAdecoder ;
    cout << "Message a decoder : " ;
    cin >> messageAdecoder ;
    cout << " " <<endl ;

    int const SizeTable((messageAdecoder.size())/(tailleN)) ;
    int y(0), tableauTranche[SizeTable] ;
    for (int i(0); i<messageAdecoder.size()-(tailleN-1); i+=tailleN)
    {
        tableauTranche[y] = atoi(messageAdecoder.substr(i,tailleN).c_str()) ;
        y++ ;
    }

    int section, aliasD(d);
    int tableauCrypte[SizeTable] ;
    for (int i(0); i<SizeTable; i++)
    {
        tableauCrypte[i] = pow(tableauTranche[i],d,n) ;
    }

    string messageDecoder, nstr, ConversionRangCar[37] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39" };
    char ConversionLetchif[37] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int o(0) ;
    for (int i(0); i<SizeTable; i++)
    {
        o=0 ;
        nstr = IntToChaine (tableauCrypte,i) ;
        while (nstr != ConversionRangCar[o])
        {
            o+=1 ;
        }
        messageDecoder += ConversionLetchif[o] ;
    }
    cout << "Message transmis : " ;
    cout << messageDecoder << endl ;


}
void laReponseD()
{
    int d,e,p,k(0) ;
    cout << "e et phi(n) : " << endl ;
    cin >> e ;
    cin >> p ;
        while ((p*k+1)%e!=0)
    {
        k++ ;
    }
    d =(p*k+1)/e ;
    cout << "d :" << d << endl ;
}

int main()
{
    cout << "Encrytion : 1" << endl;
    cout << "Decodage : 2" << endl;
    cout << "Trouver d : 3" << endl ;
    int choix;
    cin >> choix ;
    system("cls");
    switch (choix)
    {
    case 1:
        encryption() ;
        break ;
    case 2:
        decodage() ;
        break ;
    case 3:
        laReponseD() ;
        break ;
    default:
        cout << "==>[]" << endl ;
    }
    return 0;
}

