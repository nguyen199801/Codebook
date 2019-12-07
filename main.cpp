#include<iostream>
#include "Mint.h"
#include "Melt.h"
#include "Container.h"
#include <vector>
#include "generateValue.h"
using namespace std;

int main(int argc, char* argv[])
{
	//Declaring first argument seed, length and size 
	int firstArgument = atoi(argv[1]);
	int seed = atoi(argv[2]);
	int length = atoi(argv[3]);
	int size = atoi(argv[4]);
	
	if(argc == 5 || argc == 6)//Checking arguments
	{
		if(firstArgument==0)
		{
			Codebook<Mint> codebook;
			int modulus = atoi(argv[5]);
			int i=0;
			//Generate and storing Mint data
			while(i<size){
				vector<Mint> mints;
				for(int j=0;j<length;j++)
				{
					if(i==0){//Zero symbol
						Mint m;
						m.setMint(0,modulus);
						mints.push_back(m);
					}else{
						int mint = generateMint(seed, modulus);//Generate random Mint
						Mint m;
						m.setMint(mint, modulus);
						mints.push_back(m);
					}
				}
				Codeword<Mint> codeword(mints);
				codebook.add(codeword);
				i++;
			}
			codebook.display();
		}else if(firstArgument==1){
			Codebook<Melt> codebook;
			int i=0;
			//Generate and storing Melt data
			while(i<size){
				vector<Melt> melts;
				for(int j=0;j<length;j++)
				{
					if(i==0){//Zero symbol
						Melt m;
						m.setMelt('a');
						melts.push_back(m);
					}else{
						char melt = generateMelt(seed);//Generate random Melt
						Melt m;
						m.setMelt(melt);
						melts.push_back(m);
					}
				}
				Codeword<Melt> codeword(melts);
				codebook.add(codeword);	
				i++;
			}
			codebook.display();
		}
	}else{
		cout << "Incorrect Input" << endl;
	}


	/*debug
	cout << "first argument: " << firstArgument << endl;
	cout << "seed: "<< seed << endl;
	cout << "length: " << length << endl;
	cout << "size: " << size << endl; 
	*/

	return 0;
}
