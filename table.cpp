
		if (permis1 == 0 && permis2 == 1) {
			if (nrNegreAfara != 0)
			{
				for (int afaraNegru = 18; afaraNegru <= 23; afaraNegru++)
					if (joc.culoare[afaraNegru] == 2 || joc.culoare[afaraNegru] == 0 || (joc.culoare[afaraNegru] == 1 && joc.vec[afaraNegru] == 1))
						poateIntraInCasaNegru = 1;
					else
						poateIntraInCasaNegru = 0;
				if (poateIntraInCasaNegru == 0)
					ePermisSaDeaCuZarulNegru = 0;
				else
					ePermisSaDeaCuZarulNegru = 1;
				if (ePermisSaDeaCuZarulNegru == 1)
				{
					srand(time(0)); // pt a se modifica val random
					cout << endl << endl << endl;
					m = 1 + (rand() % 6);
					n = 1 + (rand() % 6);
					cout << "Jucatorul 2 a dat    " << m << "   " << n << endl << endl;

					if (m == n)
						nrMutari = 4;
					else
						nrMutari = 2;
					while (nrMutari)
					{
						if (joc.culoare[23 - m + 1] == 0)
						{
							joc.culoare[23 - m + 1] = 2;
							joc.vec[23 - m + 1]++;
							nrNegreAfara--;
							joc.afisare();
						}
						else {

							if (joc.culoare[m - 1] == 2)
							{
								joc.vec[23 - m + 1]++;
								nrNegreAfara--;
								joc.afisare();
							}
							else
								if (joc.culoare[23 - m + 1] == 1 && joc.vec[23 - m + 1] == 1)
								{
									joc.culoare[23 - m + 1] = 2;
									joc.vec[23 - m + 1] = 1;
									nrNegreAfara--;
									nrAlbeAfara++;
									joc.afisare();
								}
						}

						if (joc.culoare[23 - n + 1] == 0)
						{
							joc.culoare[23 - n + 1] = 1;
							joc.vec[23 - n + 1]++;
							nrNegreAfara--;
							joc.afisare();
						}
						else
							if (joc.culoare[23 - n + 1] == 2)
							{
								joc.vec[23 - n + 1]++;
								nrNegreAfara--;
								joc.afisare();
							}
							else
								if (joc.culoare[23 - n + 1] == 1 && joc.vec[23 - n + 1] == 1)
								{    //daca pot sa-l dau afara pe negru
									joc.culoare[n - 1] = 2;
									joc.vec[n - 1] = 1;
									nrNegreAfara++;
									nrAlbeAfara--;
									joc.afisare();
								}
						nrMutari--;
					}
					if (nrMutari != 0) {
						permis1 = 1;
						permis2 = 0;
					}
				}




			} //if (nrNegreAfara!=0)


			if (nrNegreAfara == 0 && permis1 == 0 && permis2 == 1)
			{

				srand(time(0)); // pt a se modifica val random
				cout << endl << endl << endl;
				m = 1 + (rand() % 6);
				n = 1 + (rand() % 6);
				cout << "Jucatorul 2 a dat    " << m << "   " << n << endl << endl;
				if (m == n)
					mutari = 4;
				else
					mutari = 2;
				int mutariPosibile = 0;
				for (int b = 23; b >= 0; b--) {
					if (joc.culoare[b - m] != 1 && joc.culoare[b] == 2 && joc.vec[b]>0)
						mutariPosibile++;
					if (joc.culoare[b - n] != 1 && joc.culoare[b] == 2 && joc.vec[b]>0)
						mutariPosibile++;
				}
				if (mutariPosibile<mutari)
					do {
						mutari--;
					} while (mutariPosibile<mutari);
					while (mutari) {
						if (m != n) {

							cout << "In ce ordine doriti sa mutati? 1-m,n sau 2-n,m ? ";
							cin >> ordine;
							if (ordine == 1) {

								cout << "piesa pe care o mutam este ";
								cin >> piesa;
								while (joc.vec[piesa - m] >= 2 && joc.culoare[piesa - m] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
									cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
									cin >> piesa;
									cout << endl;
								}
								cout << endl;
								if (joc.vec[piesa - m] == 1 && joc.culoare[piesa - m] == 1)
								{
									joc.vec[piesa]--;
									joc.vec[piesa - m] = 1;
									joc.culoare[piesa - m] = 2;
									mutari--;
									nrAlbeAfara++;
								}
								else {
									joc.vec[piesa]--;
									joc.vec[piesa - m]++;
									joc.culoare[piesa - m] = 2;
									mutari--;
								}
								if (joc.vec[piesa] == 0)
									joc.culoare[piesa] = 0;
								joc.afisare();
								cout << endl;
								cout << "_______________________________________________________________________";
								cout << endl;
								if (mutari) {
									if (joc.vec[piesa] == 0)
										joc.culoare[piesa] = 0;
									cout << "piesa pe care o mutam este ";
									cin >> piesa;
									while (joc.vec[piesa - n] >= 2 && joc.culoare[piesa - n] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
										cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
										cin >> piesa;
										cout << endl;
									}
									cout << endl;
									if (joc.vec[piesa - n] == 1 && joc.culoare[piesa - n] == 1)
									{
										joc.vec[piesa]--;
										joc.vec[piesa - n] = 1;
										joc.culoare[piesa - n] = 2;
										mutari--;
										nrAlbeAfara++;
									}
									else {
										joc.vec[piesa]--;
										joc.vec[piesa - n]++;
										joc.culoare[piesa - n] = 2;
										mutari--;
									}
									if (joc.vec[piesa] == 0)
										joc.culoare[piesa] = 0;
									joc.afisare();
									cout << endl;
									cout << "_______________________________________________________________________";
									cout << endl;
									if (joc.vec[piesa] == 0)
										joc.culoare[piesa] = 0;

								}
							}
							else
							{
								if (ordine == 2) {
									cout << "piesa pe care o mutam este ";
									cin >> piesa;
									while (joc.vec[piesa - n] >= 2 && joc.culoare[piesa - n] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
										cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
										cin >> piesa;
										cout << endl;
									}
									cout << endl;
									if (joc.vec[piesa - n] == 1 && joc.culoare[piesa - n] == 1)
									{
										joc.vec[piesa]--;
										joc.vec[piesa - n] = 1;
										joc.culoare[piesa - n] = 2;
										mutari--;
										nrAlbeAfara++;
									}
									else {
										joc.vec[piesa]--;
										joc.vec[piesa - n]++;
										joc.culoare[piesa - n] = 2;
										mutari--;
									}
									if (joc.vec[piesa] == 0)
										joc.culoare[piesa] = 0;
									joc.afisare();
									cout << endl;
									cout << "_______________________________________________________________________";
									cout << endl;
									if (mutari) {
										if (joc.vec[piesa] == 0)
											joc.culoare[piesa] = 0;
										cout << "piesa pe care o mutam este ";
										cin >> piesa;
										while (joc.vec[piesa - m] >= 2 && joc.culoare[piesa - m] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
											cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
											cin >> piesa;
											cout << endl;
										}
										cout << endl;
										if (joc.vec[piesa - m] == 1 && joc.culoare[piesa - m] == 1)
										{
											joc.vec[piesa]--;
											joc.vec[piesa - m] = 1;
											joc.culoare[piesa - m] = 2;
											mutari--;
											nrAlbeAfara++;
										}
										else {
											joc.vec[piesa]--;
											joc.vec[piesa - m]++;
											joc.culoare[piesa - m] = 2;
											mutari--;
										}
										if (joc.vec[piesa] == 0)
											joc.culoare[piesa] = 0;
										joc.afisare();
										cout << endl;
										cout << "_______________________________________________________________________";
										cout << endl;
										if (joc.vec[piesa] == 0)
											joc.culoare[piesa] = 0;
									}

								}


							}

						}
						else {
							if (m == n && permis1 == 0 && permis2 == 1)
							{
								cout << "piesa pe care o mutam este ";
								cin >> piesa;
								while (joc.vec[piesa - m] >= 2 && joc.culoare[piesa - m] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
									cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
									cin >> piesa;
									cout << endl;
								}
								cout << endl;
								if (joc.vec[piesa - m] == 1 && joc.culoare[piesa - m] == 1)
								{
									joc.vec[piesa]--;
									joc.vec[piesa - m] = 1;
									joc.culoare[piesa - m] = 2;
									mutari--;
									nrAlbeAfara++;
								}
								else {
									joc.vec[piesa]--;
									joc.vec[piesa - m]++;
									joc.culoare[piesa - m] = 2;
									mutari--;
								}
								if (joc.vec[piesa] == 0)
									joc.culoare[piesa] = 0;
								joc.afisare();
								cout << endl;
								cout << "_______________________________________________________________________";
								cout << endl;
								if (joc.vec[piesa] == 0)
									joc.culoare[piesa] = 0;
								if (mutari) {
									cout << "piesa pe care o mutam este ";
									cin >> piesa;
									while (joc.vec[piesa - m] >= 2 && joc.culoare[piesa - m] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
										cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
										cin >> piesa;
										cout << endl;
									}
									cout << endl;
									if (joc.vec[piesa - m] == 1 && joc.culoare[piesa - m] == 1)
									{
										joc.vec[piesa]--;
										joc.vec[piesa - m] = 1;
										joc.culoare[piesa - m] = 2;
										mutari--;
										nrAlbeAfara++;
									}
									else {
										joc.vec[piesa]--;
										joc.vec[piesa - m]++;
										joc.culoare[piesa - m] = 2;
										mutari--;
									}
									if (joc.vec[piesa] == 0)
										joc.culoare[piesa] = 0;
									joc.afisare();
									cout << endl;
									cout << "_______________________________________________________________________";
									cout << endl;
									if (joc.vec[piesa] == 0)
										joc.culoare[piesa] = 0;
									if (mutari) {
										cout << "piesa pe care o mutam este ";
										cin >> piesa;
										while (joc.vec[piesa - m] >= 2 && joc.culoare[piesa - m] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
											cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
											cin >> piesa;
											cout << endl;
										}
										cout << endl;
										if (joc.vec[piesa - m] == 1 && joc.culoare[piesa - m] == 1)
										{
											joc.vec[piesa]--;
											joc.vec[piesa - m] = 1;
											joc.culoare[piesa - m] = 2;
											mutari--;
											nrAlbeAfara++;
										}
										else {
											joc.vec[piesa]--;
											joc.vec[piesa - m]++;
											joc.culoare[piesa - m] = 2;
											mutari--;
										}
										if (joc.vec[piesa] == 0)
											joc.culoare[piesa] = 0;
										joc.afisare();
										cout << endl;
										cout << "_______________________________________________________________________";
										cout << endl;
										if (joc.vec[piesa] == 0)
											joc.culoare[piesa] = 0;
										if (mutari) {
											cout << "piesa pe care o mutam este ";
											cin >> piesa;
											while (joc.vec[piesa - m] >= 2 && joc.culoare[piesa - m] == 1 || joc.vec[piesa] == 0 || (joc.culoare[piesa] == 0 || joc.culoare[piesa] == 1)) {
												cout << "Reintroduceti piesa pe care doriti sa o mutati: ";
												cin >> piesa;
												cout << endl;
											}
											cout << endl;
											if (joc.vec[piesa - m] == 1 && joc.culoare[piesa - m] == 1)
											{
												joc.vec[piesa]--;
												joc.vec[piesa - m] = 1;
												joc.culoare[piesa - m] = 2;
												mutari--;
												nrAlbeAfara++;
											}
											else
											{
												joc.vec[piesa]--;
												joc.vec[piesa - m]++;
												joc.culoare[piesa - m] = 2;
												mutari--;
											}
											if (joc.vec[piesa] == 0)
												joc.culoare[piesa] = 0;
											joc.afisare();
											cout << endl;
											cout << "_______________________________________________________________________";
											cout << endl;
										}
									}
								}
							}
						}
					}
			}

			permis1 = 1;
			permis2 = 0;
		}

	}
	if (joc.pieseAlbe == 0)
		cout << "Jucatorul 1 a castigat! Felicitari!";
	if (joc.pieseNegre == 0)
		cout << "Jucatorul 2 a castigat! Felicitari!";

}










