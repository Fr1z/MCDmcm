/*  QUESTO PROGRAMMA ACQUISISCE N INTERI POSITIVI E NE CALCOLA IL LORO
    MINIMO COMUNE MULTIPLO E MASSSIMO COMUNE DIVISORE                   		 	  
	
       ___     _     
      / __\ __/ |____
     / _\| '__| |_  /
    / /  | |  | |/ / 
    \/   |_|  |_/___|

    github.com/Fr1z        
	
*/
    

#include <iostream>
#include <vector>         // std::vector


int Mcm(int a,int b){
	//prepare input (a>b)
    int c1 = a;
	int c2 = b;
	a = std::max(c1, c2);
	b = std::min(c1, c2);
	
	//compute
	int t=a;
	while(t%b!=0){
		t+=a;
	}
	return t;
}


int MCD(int n, int m)
{
	//adjust input
    int c1 = n;
	int c2 = m;
	n = std::max(c1, c2);
	m = std::min(c1, c2);
	
	//compute
	int r;
    while (m != 0)
    { 
       r=n%m;
       n=m;
       m=r;
    }
    
    return n;
}

std::pair<int, int> MCDmcm(std::vector<int> &myvector){
	
	int n = 0;
	int m = 0;
	int mcd = 0;
	int mcm = 0;
	
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it){
		if (n==0){
			n = *it;
			mcd = n;
			mcm = n;
		}else{
			m = *it;
			
			mcm = Mcm( mcm, m );
			mcd = MCD( mcd, m );	
						
		}
	}
	
	return std::make_pair( mcd, mcm ); 
}


int main (int argc, char *argv[])                 
{
	int n;
	std::vector<int> myvector;
	
	//retrieve input information
	if (argc <= 1){
		printf("Write the numbers you wanto to find MCD and mcm. enter 0 for compute \n");
		do
             {
				scanf("%d",&n);
				if (n>0){
					printf("ok\n");
					myvector.push_back (n);
				}
             } while (n>0);
	}else{
		//load input from console
		for (int i = 1; i < argc; ++i) 
			myvector.push_back (atoi( argv[i] ));
	}
	
	//write input recap
	std::cout << "got " << int(myvector.size()) << " numbers.\n";
	
	std::cout << "numbers are:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\n\n";
	
	
	
	//compute and write resuts
	std::pair<int, int> p = MCDmcm(myvector);
	
	std::cout << "MCD: " << p.first <<'\n';

	std::cout << "mcm: " << p.second <<'\n';
	
	
	return 0;
}
 

