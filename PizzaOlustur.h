#ifndef PizzaOlustur_H
#define PizzaOlustur_H

int pizzaOlustur(int* pizzaKonumBlgileri, Pizza* pizza){
	int adet,kanalID,pizzaID;
	cout<<"\n\n****Pizza Ekleme****\n\n"<<endl;
	cout<<"Kac Adet Pizza Ekleyeceksiniz ? "<<endl;
	cin>>adet;
	for(int loop=1;loop<=adet;loop++){
		cout<<loop<<" Pizzayi koymak istediginiz kanal noktasi ID giriniz"<<endl;
		cin>>kanalID;
		cout<<loop<<" Pizza ID giriniz ? "<<endl;
		cin>>pizzaID;
		pizzaKonumBlgileri[kanalID]=pizzaID;
	}
	return adet;
}

#endif
