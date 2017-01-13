#include <iostream>
#include "jocT"
#include <string.h>
#include <ctime>

using namespace std;

int m, n;
void masa::initializare() {

	culoare[1] = 0;
	culoare[2] = 0;
	culoare[3] = 0;
	culoare[4] = 0;
	culoare[6] = 0;
	culoare[8] = 0;
	culoare[9] = 0;
	culoare[10] = 0;
	culoare[13] = 0;
	culoare[14] = 0;
	culoare[15] = 0;
	culoare[17] = 0;
	culoare[19] = 0;
	culoare[20] = 0;
	culoare[21] = 0;
	culoare[22] = 0;             //2-negru, 1-alb, 0-nici o culoare
	culoare[0] = 1;
	culoare[5] = 2;
	culoare[7] = 2;
	culoare[11] = 1;
	culoare[12] = 2;
	culoare[16] = 1;
	culoare[18] = 1;
	culoare[23] = 2;
	vec[0] = 2;
	vec[1] = 0;
	vec[2] = 0;
	vec[3] = 0;
	vec[4] = 0;
	vec[5] = 5;
	vec[6] = 0;
	vec[7] = 3;
	vec[8] = 0;
	vec[9] = 0;
	vec[10] = 0;
	vec[11] = 5;
	vec[12] = 5;
	vec[13] = 0;
	vec[14] = 0;
	vec[15] = 0;
	vec[16] = 3;
	vec[17] = 0;
	vec[18] = 5;
	vec[19] = 0;
	vec[20] = 0;
	vec[21] = 0;
	vec[22] = 0;
	vec[23] = 2;
}
void masa::afisare() {
	cout << "            ";
	for (int i = 11; i >= 0; i--) {


		if (culoare[i] == 1)
			cout << vec[i] << "a   ";


		if (culoare[i] == 2)
			cout << vec[i] << "n   ";


		if (culoare[i] == 0)
			cout << vec[i] << "    ";


	}
	cout << endl << endl << endl << endl;

	cout << "            ";

	for (int i = 12; i <= 23; i++) {

		cout << vec[i];

		if (culoare[i] == 1)
			cout << "a   ";

		if (culoare[i] == 2)
			cout << "n   ";

		if (culoare[i] == 0)
			cout << "    ";


	}
	cout << endl;

}





int main()
{
	int r, q;
	int ordine;

	int permis1 = 1, permis2 = 0, sw = 0, permisN, permisM;
	int nrMutari, p, sw1, sw2 = 1;
	int j,piesa,mutari;
	unsigned int nrAlbeAfara = 0, nrNegreAfara = 0;
	int poateIntraInCasaAlb, ePermisSaDeaCuZarul;
    int poateIntraInCasaNegru,ePermisSaDeaCuZarulNegru;

	masa joc;
	joc.initializare();
	joc.afisare();
	while (joc.pieseAlbe>0 || joc.pieseNegre>0)                                     //LOOOOOOOOOOOPPPPPPPPPP
	{
		int sumaPuluriAlbe = 0, sumaPuluriNegre = 0;
		if (permis1 == 1 && permis2 == 0){
		if (nrAlbeAfara > 0)
		{
			for (int afaraAlb = 0; afaraAlb <= 5; afaraAlb++)
				if (joc.culoare[afaraAlb] == 1 || joc.culoare[afaraAlb] == 0 || (joc.culoare[afaraAlb] == 2 && joc.vec[afaraAlb] == 1)) // peste piese de acelasi fel sau una a adversarului

					poateIntraInCasaAlb = 1;
				else
					poateIntraInCasaAlb = 0;
			if (poateIntraInCasaAlb == 0)
				ePermisSaDeaCuZarul = 0;
			else
				ePermisSaDeaCuZarul = 1;

			if (ePermisSaDeaCuZarul == 1)
			{
				srand(time(0)); // pt a se modifica val random
				cout << endl << endl << endl;
				m = 1 + (rand() % 6);
				n = 1 + (rand() % 6);
				cout << "Jucatorul 1 a dat    " << m << "   " << n;

				if (m == n)
					nrMutari = 4;
				else
					nrMutari = 2;

				while (nrMutari)
				{
					if (joc.culoare[m-1] == 0)  // in cazul in care o piesa e afara si o reintroduc pe tabla
					{
						joc.culoare[m-1] = 1;
						joc.vec[m - 1]++;
						nrAlbeAfara--;
						joc.afisare();
					}
					else

						if (joc.culoare[m - 1] == 1)
						{
							joc.vec[m - 1]++;
							nrAlbeAfara--;
							joc.afisare();
						}

					else
						if (joc.culoare[m - 1] == 2 && joc.vec[m - 1] == 1)
						{    //daca pot sa-l dau afara pe negru
							joc.culoare[m - 1] = 1;
							joc.vec[m - 1] = 1;
							nrNegreAfara++;
							nrAlbeAfara--;
							joc.afisare();
						}

					if (joc.culoare[n - 1] == 0)
					{
						joc.culoare[n - 1] = 1;
						joc.vec[n - 1]++;
						nrAlbeAfara--;
						joc.afisare();
					}
					   else
					if (joc.culoare[n - 1] == 1)
					{
						joc.vec[n - 1]++;
						nrAlbeAfara--;
						joc.afisare();
					}
						else
					if (joc.culoare[n - 1] == 2 && joc.vec[n - 1] == 1)
					{    //daca pot sa-l dau afara pe negru
						joc.culoare[n - 1] = 1;
						joc.vec[n - 1] = 1;
						nrNegreAfara++;
						nrAlbeAfara--;
						joc.afisare();
					}

                 nrMutari--;}
				}

				permis1=0;
				permis2=1;
			}

		}              //if (nrAlbeAfara!=0)


        if(permis1 == 1 && permis2 == 0){

		int sumaPuluriAlbeInAfaraCasei;
		sumaPuluriAlbeInAfaraCasei = 0;

		for (int i = 0; i <= 17 && joc.culoare[i] == 1; i++)
			sumaPuluriAlbeInAfaraCasei = sumaPuluriAlbeInAfaraCasei + joc.vec[i];

		if  (sumaPuluriAlbeInAfaraCasei == 0 && nrAlbeAfara == 0)
		{
			srand(time(0));
			cout << endl << endl << endl;
			m = 1 + (rand() % 6);
			n = 1 + (rand() % 6);
			cout << "Jucatorul a dat    " << m << "   " << n;
			if (m == n)
			{
				int NumarMutari = 4;
				while (NumarMutari != 0)
				{
					int q;
					int copieM = m - 1;

					while (q != 1 || q != 2)
					{
						cout << "   1-mut piesa    2-scot piesa";
						cin >> q;
					}

					//    while(r>5)
					//         cout<<"Pulul aflat pe pozitia   "<<m-1;
					if (q == 2 && joc.vec[23-m+1] != 0)
					{
						joc.pieseAlbe--;
						joc.vec[23 - m + 1]--;
						NumarMutari--;
						if (joc.vec[m] == 0)
							joc.culoare[m] = 0;
					}
					else
					{

						int suma = 0; // cand nu e nici un pul pe o portiune

						if (joc.vec[23 - m + 1] == 0)
							for (int cont = 18; cont > 23 - m + 1; cont--)
								suma = suma + joc.vec[cont];


						if (suma == 0)
						{
							int copieM = 23 - m + 1;

							while (nrMutari != 0)
							{
								while (joc.vec[copieM] == 0)
									copieM++;

								joc.vec[copieM]--;
								joc.pieseAlbe--;
								nrMutari--;
							}
						}

						else
						{
							int z;
							copieM = 23 - m + 1;
							while (z < 18 || z >= copieM && joc.vec[z] == 0 && joc.vec[z+m]>=2 && joc.culoare[z+m]==2)
							{
								cout << "introduceti pozitia de pe care veti muta piesa       ";
								cin >> z;
							}
							if(joc.vec[z+m]==1 && joc.culoare[z+m] == 2)
							{
								joc.vec[z]--;
								joc.vec[z + m] = 1;
								nrNegreAfara++;
								joc.culoare[z + m] = 1;
								nrMutari--;
							}
							else
							{
								joc.vec[z]--;
								joc.vec[z + m]++;
								if (joc.vec[z] == 0)
									joc.culoare[z] = 0;
							}
						}
					}
                }
            }
		}
			srand(time(0)); // pt a se modifica val random
				cout << endl << endl << endl;
				m = 1 + (rand() % 6);
				n = 1 + (rand() % 6);
				cout << "Jucatorul 1 a dat    " << m << "   " << n << endl << endl;
				if(m==n)
                    mutari=4;
                else
                    mutari=2;
                    int mutariPosibile=0;
                    for(int b=0;b<=23;b++)  {
                        if(joc.culoare[b+m]!=2 && joc.culoare[b] == 1 && joc.vec[b]>0)
                           mutariPosibile++;
                        if(joc.culoare[b+n]!=2 && joc.culoare[b] == 1 && joc.vec[b]>0)
                           mutariPosibile++;}
                           if(mutariPosibile<mutari)
                           do{
                            mutari--;
                           }while(mutariPosibile<mutari);
                while(mutari!=0){
                 if(m!=n){

                 cout<<"In ce ordine doriti sa mutati? 1-m,n sau 2-n,m ? ";
                 cin>>ordine;
                 if(ordine==1){

                        cout<<"piesa pe care o mutam este ";
                        cin>>piesa;
				while(joc.vec[piesa+m] >= 2 && joc.culoare[piesa+m] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				if (joc.vec[piesa+m]==1 && joc.culoare[piesa+m] == 2)
                {
                    joc.vec[piesa]--;
                    joc.vec[piesa+m]=1;
                    joc.culoare[piesa+m]=1;
                    mutari--;
                    nrNegreAfara++;
                }else{
				joc.vec[piesa]--;
				joc.vec[piesa+m]++;
				joc.culoare[piesa+m]=1;
				mutari--;}
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
				joc.afisare();
				cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;
				if(mutari){
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
                    cout<<"piesa pe care o mutam este ";
                    cin>>piesa;
                while(joc.vec[piesa+n] >= 2 && joc.culoare[piesa+n] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				if (joc.vec[piesa+n]==1 && joc.culoare[piesa+n] == 2)
                {
                    joc.vec[piesa]--;
                    joc.vec[piesa+n]=1;
                    joc.culoare[piesa+n]=1;
                    mutari--;
                    nrNegreAfara++;
                }else{
				joc.vec[piesa]--;
				joc.vec[piesa+n]++;
				joc.culoare[piesa+n]=1;
				mutari--;}
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
				joc.afisare();
				cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;

				}}
				else
                    {if(ordine==2){
                       cout<<"piesa pe care o mutam este ";
                        cin>>piesa;
				while(joc.vec[piesa+n] >= 2 && joc.culoare[piesa+n] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				if (joc.vec[piesa+n]==1 && joc.culoare[piesa+n] == 2)
                {
                    joc.vec[piesa]--;
                    joc.vec[piesa+n]=1;
                    joc.culoare[piesa+n]=1;
                    mutari--;
                    nrNegreAfara++;
                }else{
				joc.vec[piesa]--;
				joc.vec[piesa+n]++;
				joc.culoare[piesa+n]=1;
				mutari--;}
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
				joc.afisare();
				cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;
				if(mutari){
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
                    cout<<"piesa pe care o mutam este ";
                    cin>>piesa;
                while(joc.vec[piesa+m] >= 2 && joc.culoare[piesa+m] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				if (joc.vec[piesa+m]==1 && joc.culoare[piesa+m] == 2)
                {
                    joc.vec[piesa]--;
                    joc.vec[piesa+m]=1;
                    joc.culoare[piesa+m]=1;
                    mutari--;
                    nrNegreAfara++;
                }else{
				joc.vec[piesa]--;
				joc.vec[piesa+m]++;
				joc.culoare[piesa+m]=1;
				mutari--;}
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
				joc.afisare();
				cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
                    }

				}}}
				else{     cout<<"piesa pe care o mutam este ";
                        cin>>piesa;
				while(joc.vec[piesa+m] >= 2 && joc.culoare[piesa+m] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				joc.vec[piesa]--;
				joc.vec[piesa+m]++;
				joc.culoare[piesa+m]=1;
				mutari--;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
				joc.afisare();
				cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
                    if (mutari){
                    cout<<"piesa pe care o mutam este ";
                        cin>>piesa;
				while(joc.vec[piesa+m] >= 2 && joc.culoare[piesa+m] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				joc.vec[piesa]--;
				joc.vec[piesa+m]++;
				joc.culoare[piesa+m]=1;
				mutari--;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
				joc.afisare();
				cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
                    if (mutari){
                    cout<<"piesa pe care o mutam este ";
                        cin>>piesa;
				while(joc.vec[piesa+m] >= 2 && joc.culoare[piesa+m] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				joc.vec[piesa]--;
				joc.vec[piesa+m]++;
				joc.culoare[piesa+m]=1;
				mutari--;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
				joc.afisare();
				cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
                    if (mutari){
                    cout<<"piesa pe care o mutam este ";
                        cin>>piesa;
				while(joc.vec[piesa+m] >= 2 && joc.culoare[piesa+m] == 2 || joc.vec[piesa] ==0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 2 ) ){
                  cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
                  cin>>piesa;
                  cout<<endl;
				}
				cout<<endl;
				joc.vec[piesa]--;
				joc.vec[piesa+m]++;
				joc.culoare[piesa+m]=1;
				mutari--;
				if(joc.vec[piesa] == 0)
                    joc.culoare[piesa] = 0;
                    joc.afisare();
                    cout<<endl;
				cout<<"_______________________________________________________________________";
				cout<<endl;  }
                    }
                    }
                    }
                               //daca m = n adica daca am dat dubla

				}
				permis1=0;
				permis2=1;//randul jucatorului 1 s-a terminat.
		}
