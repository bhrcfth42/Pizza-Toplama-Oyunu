#ifndef OptimalYolBul_H
#define OptimalYolBul_H

void OptimalYolBul(int* pizzaKonumBilgileri,int kanalBaglantiBilgileri[NodeSayisi][NodeSayisi],Pizza* pizza){
	
	int splinterUstaEnerji=500;
	int yavruNinjaEnerji=100;
	int knapsackDeger=0;
	int toplam=0;
	int lastdeger=Ev;
	bool* gezilen=new bool[NodeSayisi];
	
	Dusman* dusman=new Dusman[DusmanSayisi];
	DusmanDosyaOkuma(dusman);
	
	for(int i=0;i<NodeSayisi;i++){
		gezilen[i]=false;
	}
	
	int* val=new int[NodeSayisi];
	for(int i=0;i<NodeSayisi;i++){
		val[i]=0;
		for(int j=0;j<PizzaSayisi;j++){
			if(pizzaKonumBilgileri[i]==pizza[j].ID){
				val[i]=pizza[j].hacim;
				break;
			}
		}
	}
	
	int* gezilenNode=new int[NodeSayisi];
	for(int i=0;i<NodeSayisi;i++){
		gezilenNode[i]=0;
	}
	
	for(int i=0;i<NodeSayisi;i++){
		if(pizzaKonumBilgileri[i]!=0&&!gezilen[i]){
			int* wt=Dijkstra(kanalBaglantiBilgileri,lastdeger,gezilenNode);
			toplam+=wt[i];
			lastdeger=i;
			cout<<"\n\n"<<i<<" IDli pizzaya ulasmak icin gidilen yol guzergahi"<<endl;
			for(int j=0;j<NodeSayisi;j++){
				cout<<gezilenNode[j]<<"\t";
				knapsackDeger=Knapsack(2500,gezilenNode,val,NodeSayisi);
				
				gezilen[j]=true;
				
				if(gezilenNode[j]==i){
					for(int k=j;k<NodeSayisi;k++){
						gezilenNode[k]=0;
					}
					cout<<endl;
					EnerjiMiktariHesapla(pizzaKonumBilgileri,&splinterUstaEnerji,&yavruNinjaEnerji,gezilenNode,&knapsackDeger,j,toplam,kanalBaglantiBilgileri,pizza,dusman);
					break;
				}
			}
		}
	}
	for(int i=0;i<NodeSayisi;i++){
		gezilenNode[i]=0;
	}
	int* wt=Dijkstra(kanalBaglantiBilgileri,lastdeger,gezilenNode);
	toplam+=wt[Ev];
	cout<<"\n\nTum pizzalar toplandi.\n"<<" Eve ulasmak icin gidilen yol guzergahi"<<endl;
	for(int j=0;j<NodeSayisi;j++){
		cout<<gezilenNode[j]<<"\t";
		if(gezilenNode[j]==Ev){
			for(int k=j;k<NodeSayisi;k++){
				gezilenNode[k]=0;
			}
			cout<<endl;
			EnerjiMiktariHesapla(pizzaKonumBilgileri,&splinterUstaEnerji,&yavruNinjaEnerji,gezilenNode,&knapsackDeger,gezilenNode[j],wt[Ev],kanalBaglantiBilgileri,pizza,dusman);
			break;
		}
	}
	cout<<endl;
	cout<<endl<<"Toplam yol metre tutari : "<<toplam<<endl;
}

#endif
