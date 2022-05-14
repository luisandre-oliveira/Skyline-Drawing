#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	int X=0;															// X, n, are not appropriately named one letter variables 
	int n=0;															// that my younger self hadn´t yet learnt not to do
	int v=0;															
	int num_build=0;
	int outer_counter=0;
	int inner_counter=0;
	int prevHi=0;
	int biggest=0;
	int biggest_Ri=0;
	
	printf("How many buildings will be added?");						// num_build is the number of buildings
	scanf("%d",&num_build);

	int input[num_build][3];											// input format is [Li,Hi,Ri] being Left X, Height(Y) and Right X coordinates
	int output[v][2]; 
	
	for(outer_counter=0;outer_counter<num_build;outer_counter++) {
		for(inner_counter=0;inner_counter<3;inner_counter++){
			scanf("%d",&input[outer_counter][inner_counter]);
		}
	}

	biggest_Ri=input[0][2];
	
	for(outer_counter=0;outer_counter<num_build;outer_counter++) {		// Figuring out the biggest Ri
		if(input[outer_counter][2]>=biggest_Ri) {
			biggest_Ri=input[outer_counter][2];
		}
	}
	
	for(X=1;X<=biggest_Ri;X++) {
		int biggest=0; 													// Variable that will correspond to the largest 'Y' for each 'X'
		
		for(n=0;n<num_build;n++) {										// Here it reads the coordinates of each building	
			if(X>=input[n][0]&&X<input[n][2]) {							// If a certain X has one or more buildings this will find which is the biggest
				if(biggest<input[n][1]) {
					biggest=input[n][1];
				}
			}			
		}
		
		if(prevHi!=biggest) {											// If the biggest 'Y' found is different from the 'Y' on the previous X ('prevHi')	
			v=v+1; 														// the variables 'X' and 'biggest' are added to the output vector
			output[v-1][0]=X;									
			output[v-1][1]=biggest;
		} 		
		prevHi=biggest;  
	}
		
	printf("\n\n");
	
	for(outer_counter=0;outer_counter<v;outer_counter++){				// Displays the output vector corresponding to the skyline 								
		for(inner_counter=0;inner_counter<2;inner_counter++){			// Ex: [1, 11] with 1  and 11 being the X and Y coordinates respectively
			printf("%d ",output[outer_counter][inner_counter]);			
		}																
	}
}			
