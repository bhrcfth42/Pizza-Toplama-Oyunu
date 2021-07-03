#ifndef DusmanDosyaOkuma_H
#define DusmanDosyaOkuma_H

void DusmanDosyaOkuma(Dusman* dusman){
	ifstream dusmanBilgileriDosyasi("DusmanBilgisi.txt");
	int loop1=0;
	string satir="";
	if(dusmanBilgileriDosyasi.is_open()){
		while(getline(dusmanBilgileriDosyasi,satir)){
			for(int loop=0;loop<satir.length();loop++){
				if(satir[loop]==','){
					satir[loop]=' ';
				}
				else if(satir[loop]=='D')
					satir[loop]='0';
			}
			stringstream degerler(satir);
			degerler>>dusman[loop1].ID>>dusman[loop1].Direnc>>dusman[loop1].Konum>>dusman[loop1].KaybettigiSure;
			loop1++;
		}
		dusmanBilgileriDosyasi.close();
	}
}

#endif
