#ifndef RaporVer_H
#define RaporVer_H

void RaporVer(int* knapsackDeger,Dusman* dusman,Pizza* pizza,int* splinterUstaEnerji,int* yavruNinjaEnerji,int* pizzaKonumBilgileri,int* yenilenPizzaDugum){
	
	int pizzaToplamEv=0;
	
	cout<<"Karsilasilan dusman bilgileri : \t";
	for(int i =0;i<DusmanSayisi;i++){
		if(dusman[i].Konum==INT_MAX){
			cout<<dusman[i].ID<<" ";
		}
	}
	cout<<endl;
	cout<<"Toplamis oldugu pizzalarin kalorisi : \t"<<*knapsackDeger<<endl;
	for(int i=0;i<NodeSayisi;i++){
		if(pizzaKonumBilgileri[i]>0){
			pizzaToplamEv+=pizza[pizzaKonumBilgileri[i]].kalori;
		}
	}
	cout<<"Eve getirdigi pizzalarin kalorisi : \t"<<pizzaToplamEv<<endl;
	
	cout<<"Usta Splinterin kalan enerji seviyesi : \t"<<*splinterUstaEnerji<<endl;
	int pizzaToplamSplinterUsta=*knapsackDeger-pizzaToplamEv;
	cout<<"Usta Splintera dusen pizza kalori miktari : \t"<<pizzaToplamSplinterUsta<<endl;
	cout<<"Yavru Ninjalarin kalan enerji seviyesi : \t"<<*yavruNinjaEnerji<<endl;
	cout<<"Yavru Ninjalara dusen pizza kalori miktari : \t"<<pizzaToplamEv<<"/4="<<pizzaToplamEv/4<<endl;
	
}

#endif
