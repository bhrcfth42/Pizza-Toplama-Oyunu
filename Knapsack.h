#ifndef Knapsack_H
#define Knapsack_H

int max(int a, int b){
	
	if(a>b){
    	return a;
	} 
	else{
		return b;
	}
	
}

int Knapsack(int W, int wt[], int val[], int n) {
	
	int knap[n+1][W+1];
   
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
        	if (i==0 || w==0){
        		knap[i][w] = 0;
			}
        	else if (wt[i-1] <= w){
        		knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
			}
        	else{
        		knap[i][w] = knap[i-1][w];
			}
    	}
	}
	
	return knap[n][W];
   
}

#endif
