#include <iostream>
#include <fstream>
#include <sstream>
#define NodeSayisi 40
#define PizzaSayisi 4
#define Ev 0
#define CantaKapasite 2500
#define DusmanSayisi 6

using namespace std;

#include "Graph.h"
#include "DosyaOkuma.h"
#include "Pizza.h"
#include "PizzaDosyaOkuma.h"
#include "PizzaOlustur.h"
#include "Dijkstra.h"
#include "Dusman.h"
#include "DusmanDosyaOkuma.h"
#include "RaporVer.h"
#include "Uyari.h"
#include "EnerjiMiktariHesapla.h"
#include "Knapsack.h"
#include "OptimalYolBul.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Graph* kanalBaglantiBilgileriGraph = createGraph(NodeSayisi);
	DosyaOkuma(kanalBaglantiBilgileriGraph);
	cout<<"Kanal Baglanti Bilgileri"<<endl;
	printGraph(kanalBaglantiBilgileriGraph);
	
	Pizza* pizza=new Pizza[PizzaSayisi];
	PizzaDosyaOkuma(pizza);

	int* pizzaKonumBilgileri=new int[NodeSayisi];
	for(int i=0;i<NodeSayisi;i++){
		pizzaKonumBilgileri[i]=0;
	}
	
	int pizzaAdet=pizzaOlustur(pizzaKonumBilgileri,pizza);
	
	int kanalBaglantiBilgileri[NodeSayisi][NodeSayisi];
	for(int i=0;i<NodeSayisi;i++)
		for(int j=0;j<NodeSayisi;j++)
			kanalBaglantiBilgileri[i][j]=0;
	for(int i=0;i<NodeSayisi;i++){
		AdjListNode* adjLists=kanalBaglantiBilgileriGraph->array[i].head;
		while(adjLists){
			kanalBaglantiBilgileri[i][adjLists->dest]=adjLists->agirlik;
			adjLists=adjLists->next;
		}
	}
	
	OptimalYolBul(pizzaKonumBilgileri,kanalBaglantiBilgileri,pizza);

	return 0;
	
}
