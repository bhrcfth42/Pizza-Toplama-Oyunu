#ifndef EnerjiMiktariHesapla_H
#define EnerjiMiktariHesapla_H

void EnerjiMiktariHesapla(int* pizzaKonumBilgileri,int* splinterUstaEnerji,int* yavruNinjaEnerji,int* gezilenNode,int* knapsackDeger,int hedefID,int yolMetre,int kanalBaglantiBilgileri[NodeSayisi][NodeSayisi],Pizza* pizza,Dusman* dusman){
	int yolZamanDakika=(yolMetre/2)/60;
	*splinterUstaEnerji-=yolMetre/5;
	for(int i=0;i<NodeSayisi;i++){
		for(int j=0;j<DusmanSayisi;j++){
			if(gezilenNode[i]==dusman[j].Konum){
				*splinterUstaEnerji-=dusman[j].Direnc;
				dusman[j].Konum=INT_MAX;
				yolZamanDakika+=dusman[j].KaybettigiSure;
			}
		}
	}
	int yavruEnerjiKaybi=(yolZamanDakika/60)*50;
	*yavruNinjaEnerji-=yavruEnerjiKaybi;
	Uyari(pizzaKonumBilgileri,splinterUstaEnerji,yavruNinjaEnerji,knapsackDeger,hedefID,kanalBaglantiBilgileri,gezilenNode,pizza,dusman);
}

#endif
