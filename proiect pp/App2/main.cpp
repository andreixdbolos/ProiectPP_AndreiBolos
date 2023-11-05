#include <bits/stdc++.h>

#include "../Shared/Data/Data.cpp"
#include "../Shared/Data/Comanda.cpp"
#include "../Shared/Data/Produs.cpp"

void citireComenzi(int &nrComenzi, std::vector<Comanda> &comenzi);
void afisareCos(int nrProduseCos, std::vector<Produs> cos);
void citireCos(int &nrProduseCos, std::vector<Produs> &cos);
void adaugareProdusCos(int &nrProduseCos, std::vector<Produs> &cos, const std::string& codDeBare , const std::string& denumire, double pret, int cantitate);
void cumparare(int &nrComenzi, std::vector<Comanda> &comenzi, int &nrProduseCos, std::vector<Produs> &cos, Data data);      
void stergereProdusCos(int &nrProduseCos, std::vector<Produs> &cos, const std::string& codDeBare); 
void modificareProdusCos(int &nrProduseCos, std::vector<Produs> &cos, const std::string& codDeBare , const std::string& nouCodDeBare ,const std::string& denumire, double pret, int cantitate);

int main(int argc, char* argv[])
{
    std::string optiune = argv[1];

    std::ifstream fin("../Shared/Files/comenzi.txt");
    std::vector<Comanda> comenzi;
    std::vector<Produs> cos;
    int nrComenzi = 0;
    int nrProduseCos = 0;
    citireComenzi(nrComenzi, comenzi);
    citireCos(nrProduseCos, cos);
    if (optiune == "afisareCos")
        afisareCos(nrProduseCos, cos);
    else
    if (optiune == "stergereProdusCos")
        stergereProdusCos(nrProduseCos, cos, argv[2]);       
    else
    if (optiune == "modificareProdusCos")
        modificareProdusCos(nrProduseCos, cos, argv[2] , argv[3], argv[4], atof(argv[5]), atoi(argv[6]));
    else
    if (optiune == "adaugareProdusCos")
        adaugareProdusCos(nrProduseCos, cos, argv[2], argv[3], atof(argv[4]), atoi(argv[5]));
    else
    if (optiune == "adaugareComanda")
        cumparare(nrComenzi, comenzi, nrProduseCos, cos, argv[2]);
    else       
        std::cout << "Comanda gresita";
        
    return 0;
}
void afisareCos(int nrProduseCos, std::vector<Produs> cos)
{
    for (int i = 0; i < nrProduseCos; ++i)
    {   std::cout << "Produsul " << i + 1 << ":\n";
        std::cout << cos[i] << '\n';
    }
}
void citireCos(int &nrProduseCos, std::vector<Produs> &cos)
{
    std::ifstream fin("../Shared/Files/cos.txt");
    fin >> nrProduseCos;
    for (int i = 0; i < nrProduseCos; ++i)
    {   
        Produs produs;
        fin >> produs;
        cos.push_back(produs);
    }
    fin.close();
}   
void adaugareProdusCos(int &nrProduseCos, std::vector<Produs> &cos , const std::string& codDeBare , const std::string& denumire, double pret, int cantitate)
{
    std::ofstream fout("../Shared/Files/cos.txt");
    cos.push_back(Produs(codDeBare, denumire, cantitate, pret));
    nrProduseCos++;
    fout << nrProduseCos << '\n';
    for (int i = 0; i < nrProduseCos; ++i)
    {   
        fout << cos[i] << '\n';
    }
    fout.close();
}
void stergereProdusCos(int &nrProduseCos, std::vector<Produs> &cos, const std::string& codDeBare)
{
    std::ofstream fout("../Shared/Files/cos.txt");
    for (int i = 0; i < nrProduseCos; ++i)
    {   
        if (cos[i].getCodDeBare() == codDeBare)
        {
            cos.erase(cos.begin() + i);
            nrProduseCos--;
            break;
        }
    }
    fout << nrProduseCos << '\n';
    for (int i = 0; i < nrProduseCos; ++i)
    {   
        fout << cos[i] << '\n';
    }
    fout.close();
}
void modificareProdusCos(int &nrProduseCos, std::vector<Produs> &cos, const std::string& codDeBare, const std::string& nouCodDeBare, const std::string& denumire, double pret, int cantitate)
{
    std::ofstream fout("../Shared/Files/cos.txt");
    for (int i = 0; i < nrProduseCos; ++i)
    {   
        if (cos[i].getCodDeBare() == codDeBare)
        {
            cos[i].setCodDeBare(nouCodDeBare);
            cos[i].setDenumire(denumire);
            cos[i].setPret(pret);
            cos[i].setCantitate(cantitate);
            break;
        }
    }
    fout << nrProduseCos << '\n';
    for (int i = 0; i < nrProduseCos; ++i)
    {   
        fout << cos[i] << '\n';
    }
    fout.close();
}    
void citireComenzi(int &nrComenzi, std::vector<Comanda> &comenzi)
{
    std::ifstream fin("../Shared/Files/comenzi.txt");
    fin >> nrComenzi;
    for (int i = 0; i < nrComenzi; ++i)
    {   
        std::vector<Produs> produse;
        int nrProduse = 0;
        fin >> nrProduse;
        for (int j = 0; j < nrProduse; ++j)
        {
            Produs produs;
            fin >> produs;
            produse.push_back(produs);
        }
        Data data;
        fin >> data;
        comenzi.push_back(produse);
        comenzi[i].setData(data);
        std::string empty;
        std::getline(fin, empty);
    };
    fin.close();
}
void cumparare(int &nrComenzi, std::vector<Comanda> &comenzi, int &nrProduseCos, std::vector<Produs> &cos, Data data)
{
    std::ofstream fout("../Shared/Files/comenzi.txt");
    comenzi.push_back(cos);
    comenzi[nrComenzi].setData(data);
    nrComenzi++;
    fout << nrComenzi << '\n';
    for (int i = 0; i < nrComenzi; ++i)
    {   
        fout << nrProduseCos << '\n';
        fout << comenzi[i] << '\n';
    }
    cos.clear();
    nrProduseCos = 0; 
    fout.close();
    std::ofstream fout2("../Shared/Files/cos.txt");
    fout2 << nrProduseCos << '\n'; 
}
