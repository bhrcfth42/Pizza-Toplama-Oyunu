#ifndef DosyaOkuma_H
#define DosyaOkuma_H

void DosyaOkuma(Graph* graph){
	ifstream kanalBaglantiBilgileriDosyasi("KanalBaglantiBilgileri.txt");
	int loop1=0;
	string satir="";
	if(kanalBaglantiBilgileriDosyasi.is_open()){
		while(getline(kanalBaglantiBilgileriDosyasi,satir)){
			int loop2=0;
			for(int loop=0;loop<satir.length();loop++){
				if(satir[loop]==','){
					satir[loop]=' ';
				}
				else if(satir[loop]=='-')
					satir[loop]='0';
			}
			stringstream degerler(satir);
			int n;
			while (degerler >> n) {
				if(n!=0){
					addEdge(graph,loop1,loop2,n);
				}     			
     			loop2++;
			}
			loop1++;
		}
		kanalBaglantiBilgileriDosyasi.close();
	}
}

#endif
