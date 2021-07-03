#ifndef Uyari_H
#define Uyari_H

void Uyari(int* pizzaKonumBilgileri,int* splinterUstaEnerji,int* yavruNinjaEnerji,int* knapsackDeger,int hedefID,int kanalBaglantiBilgileri[NodeSayisi][NodeSayisi],int* gezilenNode,Pizza* pizza,Dusman* dusman){
	
	int* yenilenPizzaDugum=new int[NodeSayisi];
	for(int i=0;i<NodeSayisi;i++){
		yenilenPizzaDugum[i]=0;
	}
	
	if(*splinterUstaEnerji<200){
		Pizza enKucuk=pizza[0];
		
		for(int i=0;i<NodeSayisi;i++){
			int pizzaID=pizzaKonumBilgileri[gezilenNode[i]];
			if(pizzaID!=0){
				if(enKucuk.kalori>pizza[pizzaID].kalori){
					enKucuk=pizza[pizzaID];
					yenilenPizzaDugum[gezilenNode[i]]=enKucuk.ID;
				}
			}
		}
		*splinterUstaEnerji+=enKucuk.kalori;
	}
	if(*yavruNinjaEnerji<20){
		int* eveDonus=new int[NodeSayisi];
		for(int i=0;i<NodeSayisi;i++){
			eveDonus[i]=0;
		}
		int* wt=Dijkstra(kanalBaglantiBilgileri,hedefID,eveDonus);
		cout<<"Eve Uzaklik : "<<wt[Ev]<<endl;
		*splinterUstaEnerji-=wt[Ev];
	}
	if(hedefID==Ev){
		if(*splinterUstaEnerji>0){
			cout<<"Gorev Basarili."<<endl;
		}
		else{
			cout<<"Gorev Basarisiz."<<endl;
		}
		RaporVer(knapsackDeger,dusman,pizza,splinterUstaEnerji,yavruNinjaEnerji,pizzaKonumBilgileri,yenilenPizzaDugum);
	}
}

#endif
