#include <bits/stdc++.h>

#include "../Shared/Data/Data.cpp"
#include "../Shared/Data/Comanda.cpp"
#include "../Shared/Data/Produs.cpp"


void afisareProduse(int nrProduseStoc, std::vector<Produs> produse);
void citireProduse(int &nrProduseStoc, std::vector<Produs> &produse);
void adaugareProdus(int &nrProduseStoc, std::vector<Produs> &produse, const std::string& codDeBare , const std::string& denumire, double pret, int cantitate);
void stergereProdus(int &nrProduseStoc, std::vector<Produs> &produse, const std::string& codDeBare);
void modificareProdus(int &nrProduseStoc, std::vector<Produs> &produse, const std::string& codDeBare, const std::string& nouCodeDeBare, const std::string& denumire, double pret, int cantitate);
void afisareComenzi(int nrComenzi, std::vector<Comanda> comenzi);
void citireComenzi(int &nrComenzi, std::vector<Comanda> &comenzi);

int main(int argc, char* argv[])
{   
    std::string optiune = argv[1];

    std::ifstream fin("../Shared/Files/stoc.txt");
    std::vector<Produs> produse;
    std::vector<Comanda> comenzi;
    int nrComenzi = 0;
    int nrProduseStoc = 0;
    citireProduse(nrProduseStoc, produse);
    citireComenzi(nrComenzi, comenzi);
    if(optiune == "afisareProduse")
        afisareProduse(nrProduseStoc, produse);
    else
    if (optiune == "adaugareProdus")
        adaugareProdus(nrProduseStoc, produse, argv[2], argv[3], atof(argv[4]), atoi(argv[5]));
    else
    if (optiune == "stergereProdus")
        stergereProdus(nrProduseStoc, produse, argv[2]);       
    else
    if (optiune == "modificareProdus")
        modificareProdus(nrProduseStoc, produse, argv[2], argv[3], argv[4], atof(argv[5]), atoi(argv[6]));
    else
    if (optiune == "afisareComenzi")
        afisareComenzi(nrComenzi, comenzi);
    else    
    std::cout << "Comanda gresita";

    return 0;
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
void afisareComenzi(int nrComenzi, std::vector<Comanda> comenzi)
{
    for (int i = 0; i < nrComenzi; ++i)
    {   std::cout << "Comanda " << i + 1 << '\n';
        std::cout << comenzi[i]<< '\n';
    }
}
void afisareProduse(int nrProduseStoc, std::vector<Produs> produse)
{
    for (int i = 0; i < nrProduseStoc; ++i)
    {   std::cout << "Produsul " << i + 1 << ":\n";
        std::cout << produse[i] << '\n';
    }
}
void citireProduse(int &nrProduseStoc, std::vector<Produs> &produse1)
{
    std::ifstream fin("../Shared/Files/stoc.txt");
    fin >> nrProduseStoc;
    for (int i = 0; i < nrProduseStoc; ++i)
    {   
        Produs produs;
        fin >> produs;
        produse1.push_back(produs);
    }
    fin.close();
}

void adaugareProdus(int &nrProduseStoc, std::vector<Produs> &produse, const std::string& codDeBare , const std::string& denumire, double pret, int cantitate)
{
    std::ofstream fout("../Shared/Files/stoc.txt");
    Produs produs(codDeBare, denumire, pret, cantitate);
    produse.push_back(produs);
    nrProduseStoc++;
    fout << nrProduseStoc << '\n';
    for (int i = 0; i < nrProduseStoc; ++i)
    {
        fout << produse[i] << '\n';
    }
}
void stergereProdus(int &nrProduseStoc, std::vector<Produs> &produse, const std::string& codDeBare)
{
    std::ofstream fout("../Shared/Files/stoc.txt");
    for (int i = 0; i < nrProduseStoc; ++i)
    {
        if (produse[i].getCodDeBare() == codDeBare)
        {
            produse.erase(produse.begin() + i);
            nrProduseStoc--;
            break;
        }
    }
    fout << nrProduseStoc << '\n';
    for (int i = 0; i < nrProduseStoc; ++i)
    {
        fout << produse[i] << '\n';
    }
    fout.close();
}
void modificareProdus(int &nrProduseStoc, std::vector<Produs> &produse, const std::string& codDeBare ,const std::string& nouCodeDeBare, const std::string& denumire, double pret, int cantitate)
{
    std::ofstream fout("../Shared/Files/stoc.txt");
    for (int i = 0; i < nrProduseStoc; ++i)
    {
        if (produse[i].getCodDeBare() == codDeBare)
        {
            produse[i].setCodDeBare(nouCodeDeBare);
            produse[i].setDenumire(denumire);
            produse[i].setPret(pret);
            produse[i].setCantitate(cantitate);
            break;
        }
    }
    fout << nrProduseStoc << '\n';
    for (int i = 0; i < nrProduseStoc; ++i)
    {
        fout << produse[i] << '\n';
    }
    fout.close();
}