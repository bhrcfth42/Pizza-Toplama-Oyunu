#ifndef PizzaDosyaOkuma_H
#define PizzaDosyaOkuma_H

void PizzaDosyaOkuma(Pizza* pizza){
	ifstream pizzaBilgileriDosyasi("PizzaBilgileri.txt");
	int loop1=0;
	string satir="";
	if(pizzaBilgileriDosyasi.is_open()){
		while(getline(pizzaBilgileriDosyasi,satir)){
			for(int loop=0;loop<satir.length();loop++){
				if(satir[loop]==','){
					satir[loop]=' ';
				}
				else if(satir[loop]=='P')
					satir[loop]='0';
			}
			stringstream degerler(satir);
			degerler>>pizza[loop1].ID>>pizza[loop1].boyut>>pizza[loop1].kalori>>pizza[loop1].hacim;
			loop1++;
		}
		pizzaBilgileriDosyasi.close();
	}
}

#endif
