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

void codonsToAminos(std::string sequence){
	std::map<std::string, std::string> codontable = {
		{"TTT", "Phenylalanine"},
        {"TTC", "Phenylalanine"},

        {"TTA", "Leucine"},
        {"TTG", "Leucine"},
        {"CTT", "Leucine"},
        {"CTC", "Leucine"},
        {"CTA", "Leucine"},
        {"CTG", "Leucine"},

        {"ATT", "Isoleucine"},
        {"ATC", "Isoleucine"},
        {"ATA", "Isoleucine"},

        {"ATG", "Methionine"},

        {"GTT", "Valine"},
        {"GTC", "Valine"},
        {"GTA", "Valine"},
        {"GTG", "Valine"},

        {"TCT", "Serine"},
        {"TCC", "Serine"},
        {"TCA", "Serine"},
        {"TCG", "Serine"},
        {"AGT", "Serine"},
        {"AGC", "Serine"},

        {"CCT", "Proline"},
        {"CCC", "Proline"},
        {"CCA", "Proline"},
        {"CCG", "Proline"},

        {"ACT", "Threonine"},
        {"ACC", "Threonine"},
        {"ACA", "Threonine"},
        {"ACG", "Threonine"},

        {"GCT", "Alanine"},
        {"GCC", "Alanine"},
        {"GCA", "Alanine"},
        {"GCG", "Alanine"},

        {"TAT", "Tyrosine"},
        {"TAC", "Tyrosine"},

        {"TAA", "STOP"},
        {"TAG", "STOP"},
        {"TGA", "STOP"},

        {"CAT", "Histidine"},
        {"CAC", "Histidine"},

        {"CAA", "Glutamine"},
        {"CAG", "Glutamine"},

        {"AAT", "Asparagine"},
        {"AAC", "Asparagine"},

        {"AAA", "Lysine"},
        {"AAG", "Lysine"},

        {"GAT", "Aspartic acid"},
        {"GAC", "Aspartic acid"},

        {"GAA", "Glutamic acid"},
        {"GAG", "Glutamic acid"},

        {"TGT", "Cysteine"},
        {"TGC", "Cysteine"},

        {"TGG", "Tryptophan"},

        {"CGT", "Arginine"},
        {"CGC", "Arginine"},
        {"CGA", "Arginine"},
        {"CGG", "Arginine"},
        {"AGA", "Arginine"},
        {"AGG", "Arginine"},

        {"GGT", "Glycine"},
        {"GGC", "Glycine"},
        {"GGA", "Glycine"},
        {"GGG", "Glycine"},
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
    std::cout << "3: Codons --> Amino Acids" << '\n';
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
    	codonsToAminos(sequence);
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
