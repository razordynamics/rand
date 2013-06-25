#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

int main(){
	srand(time(NULL));
	ifstream fin;
	vector<string> name_list;
	string infile;
	string outfile;
	int size;
	cout << "Enter file to load" << endl;
	cin >> infile;
	cout << "Enter file to save to" << endl;
	cin >> outfile;
	cout << "Enter sample size" << endl;
	cin >> size;
	fin.open(infile);
	while(!fin.eof()){
		string temp;
		fin >> temp;
		name_list.push_back(temp);
	}
	if(size<=name_list.size()){
		if(size>(name_list.size()/2)){cout << "sample size greater than half, poor random distribution expected" << endl;}
		vector<string> chosen;
		for(int i=0; i<size; i++){
			int random=(rand()%name_list.size());
			chosen.push_back(name_list[random]);
			name_list.erase(name_list.begin()+random);
	}

		ofstream fout;
		fout.open(outfile);
	for(int i=0; i<chosen.size(); i++){
	cout << chosen[i] << endl;
	fout << chosen[i] << endl;
	}
	}
	else{cout << "sample size greater than name_list size, cannot continue" << endl; }
	return 0;
}