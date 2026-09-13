#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
 
void results(std::string sequence);
void DnaSearch(std::string sequence);
void menu(std::string sequence);

void results(std::string sequence) {

    int lenght = sequence.length();

    std::cout << "total: " << lenght << '\n';

    int aCount = 0;
    int tCount = 0;
    int cCount = 0;
    int gCount = 0;
    int gcCount = 0;
    int atCount = 0;

    for (char base : sequence) {
        if (base == 'A') {
            aCount++;
        }
    }

    for (char base : sequence) {
        if (base == 'T') {
            tCount++;
        }
    }

    for (char base : sequence) {
        if (base == 'C') {
            cCount++;
        }
    }

    for (char base : sequence) {
        if (base == 'G') {
            gCount++;
        }
    }

    for (char base : sequence) {
        if (base == 'G' || base == 'C') {
            gcCount++;
        }
    }

    for (char base : sequence) {
        if (base == 'A' || base == 'T') {
            atCount++;
        }
    }
    
    double aPercentage = (static_cast<double>(aCount) / sequence.length()) * 100;
    double cPercentage = (static_cast<double>(cCount) / sequence.length()) * 100;
    double gPercentage = (static_cast<double>(gCount) / sequence.length()) * 100;
    double tPercentage = (static_cast<double>(tCount) / sequence.length()) * 100;
    double gcPercentage = (static_cast<double>(gcCount) / sequence.length()) * 100;
    double atPercentage = (static_cast<double>(atCount) / sequence.length()) * 100;
        
    std::cout << "---------results-----------" << '\n';
    std::cout << "adenine(a): " << aCount << " (" << aPercentage<< "%" << ")" <<'\n';
    std::cout << "thymine(t): " << tCount << " ("<< tPercentage<< "%"<< ")" <<'\n';
    std::cout << "cytosine(c): " << cCount << " ("<< cPercentage<< "%"<< ")" <<'\n';
    std::cout << "guanine(g): " << gCount << " ("<< gPercentage<< "%"<< ")" <<'\n';
    std::cout << "gc: " << gcCount << '\n';
    std::cout << "gc percentage: " << gcPercentage << "%" << '\n';
    std::cout << "at percentage: " << atPercentage << "%" << '\n';
    std::cout << "---------------------------" << '\n';
    std::cout << '\n';
}

void DnaSearch(std::string sequence) {

    std::string search;

    std::cout << "What sequence would you like to search for: ";
    std::cin >> search;

    std::size_t position = sequence.find(search);

    if (position != std::string::npos) {
        std::cout << "Sequence found!" << '\n';
        std::cout << "Position: " << position << '\n';
    }
    else {
        std::cout << "Sequence not found." << '\n';
    }

    std::cout << '\n';
    
}

void mutation(std::string& sequence){
	double mutationPercent;
	std::cout << "how much percentage of the original dna would you like to mutate: ";
	std::cin >> mutationPercent;
	
	mutationPercent = mutationPercent / 100.0;	
	int mutationAmount = sequence.length() * mutationPercent;
	
	for (int i = 0; i <mutationAmount; i++){
		
	
		int position = rand() % sequence.length();
	
		char base[] = {'A', 'T', 'C','G'};
		char oldBases = sequence[position];
		char newbases;
	
		do {
			newbases = base[rand() % 4];
		} while (newbases == oldBases);
	
		sequence[position] = newbases;	
		std::cout << "mutation at " << position << ":" << oldBases <<  " --> " << newbases << '\n';
	}
}

void dnaToAminos(std::string sequence){
	std::cout << "Amino-acid biochemical properties: " << "nonpolar(np), polar(p), basic(b), acidic(a) " << '\n';
	std::cout << "----------------------------------------------------------------------------"<< '\n';
	std::map<std::string, std::string> codontable = {
		{"TTT", "Phenylalanine (np)"},
        {"TTC", "Phenylalanine (np)"},

        {"TTA", "Leucine (np)"},
        {"TTG (potential start codon)", "Leucine (np)"},
        {"CTT", "Leucine (np)"},
        {"CTC", "Leucine (np)"},
        {"CTA", "Leucine (np)"},
        {"CTG", "Leucine (np)"},

        {"ATT", "Isoleucine (np)"},
        {"ATC", "Isoleucine (np)"},
        {"ATA", "Isoleucine (np)"},

        {"ATG (potential start codon)", "Methionine (np)"},

        {"GTT", "Valine (np)"},
        {"GTC", "Valine (np)"},
        {"GTA", "Valine (np)"},
        {"GTG (potential start codon)", "Valine (np)"},

        {"TCT", "Serine (p)"},
        {"TCC", "Serine (p)"},
        {"TCA", "Serine (p)"},
        {"TCG", "Serine (p)"},
        {"AGT", "Serine (p)"},
        {"AGC", "Serine (p)"},

        {"CCT", "Proline (np)"},
        {"CCC", "Proline (np)"},
        {"CCA", "Proline (np)"},
        {"CCG", "Proline (np)"},

        {"ACT", "Threonine (p)"},
        {"ACC", "Threonine (p)"},
        {"ACA", "Threonine (p)"},
        {"ACG", "Threonine (p)"},

        {"GCT", "Alanine (np)"},
        {"GCC", "Alanine (np)"},
        {"GCA", "Alanine (np)"},
        {"GCG", "Alanine (np)"},

        {"TAT", "Tyrosine (p)"},
        {"TAC", "Tyrosine (p)"},

        {"TAA", "STOP"},
        {"TAG", "STOP"},
        {"TGA", "STOP"},

        {"CAT (potential start codon)", "Histidine (b)"},
        {"CAC (potential start codon)", "Histidine (b)"},

        {"CAA", "Glutamine (p)"},
        {"CAG", "Glutamine (p)"},

        {"AAT", "Asparagine (p)"},
        {"AAC", "Asparagine (p)"},

        {"AAA (potential start codon)", "Lysine (b)"},
        {"AAG (potential start codon)", "Lysine (b)"},

        {"GAT", "Aspartic acid (a)"},
        {"GAC", "Aspartic acid (a)"},

        {"GAA", "Glutamic acid (a)"},
        {"GAG", "Glutamic acid (a)"},

        {"TGT", "Cysteine (p)"},
        {"TGC", "Cysteine (p)"},

        {"TGG", "Tryptophan (np)"},

        {"CGT (potential start codon)", "Arginine (b)"},
        {"CGC (potential start codon)", "Arginine (b)"},
        {"CGA (potential start codon)", "Arginine (b)"},
        {"CGG (potential start codon)", "Arginine (b)"},
        {"AGA (potential start codon)", "Arginine (b)"},
        {"AGG (potential start codon)", "Arginine (b)"},

        {"GGT", "Glycine (np)"},
        {"GGC", "Glycine (np)"},
        {"GGA", "Glycine (np)"},
        {"GGG", "Glycine (np)"},
	};
	
	for (int i = 0; i + 2 < sequence.length(); i += 3){
		std::string codon = sequence.substr(i, 3);		
		std::cout << codon << "-->" <<codontable[codon] << '\n';
	}
}

void cancerDetect(std::string sequence){
	
}

void menu(std::string sequence) {

    std::cout << "**********************************" << '\n';
    std::cout << "1: Dna Sequence Search" << '\n';
    std::cout << "2: Mutation Sim (will be permenant)" << '\n';
    std::cout << "3: dna --> Amino Acids" << '\n';
    std::cout << "4: Cancer Detect" << '\n';
    std::cout << "5: PRINT YOUR FULL RESULTS" << '\n';
    std::cout << "**********************************" << '\n';

    std::string choice;

    std::cout << "what more would you like to do: ";
    std::cin >> choice;

    std::cout << "**********************************" << '\n';

    if (choice == "1") {
        DnaSearch(sequence);
    }

    if (choice == "2") {
    	results(sequence);
    	std::cout << sequence << '\n';
        mutation(sequence);
        std::cout << sequence << '\n';
    }

    if (choice == "3") {
    	dnaToAminos(sequence);
    }

    if (choice == "4") {
        std::cout << "cancer detecction soon.." << '\n';
    }

    if (choice == "5") {
        results(sequence);
    }
}


int main() {

    int userinput;

    std::cout << "what length sequence would you like: ";
    std::cin >> userinput;

    std::random_device rd;
    std::mt19937 generator(rd());

    std::vector<std::string> dna = {"A", "T", "C", "G"};

    std::string sequence;
    std::uniform_int_distribution<int> distribution(0, 3);

    for (int i = 0; i < userinput; i++) {
        int randomindex = distribution(generator);
        sequence += dna[randomindex];
    }

    std::cout << '\n';
    std::cout << "Original DNA:" << '\n';
    std::cout << sequence << '\n';
    std::cout << '\n';


    std::string complementary;

    for (char base : sequence) {
        if (base == 'A') {
            complementary += 'T';
        }
        else if (base == 'T') {
            complementary += 'A';
        }
        else if (base == 'C') {
            complementary += 'G';
        }
        else if (base == 'G') {
            complementary += 'C';
        }
    }

    std::cout << "Complementary DNA:" << '\n';
    std::cout << complementary << '\n';
    std::cout << '\n';

    while (true) {
    	menu(sequence);
	}
}
