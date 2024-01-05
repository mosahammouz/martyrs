#include<iostream>
#include<fstream>
#include<string>
#include"myclasses.h"
using namespace std;






	



	void menu() {


		cout << "1.An option to insert new location record." << endl;
		cout << "2.An option to update an existing location." << endl;
		cout << "3.An option to delete an existing location." << endl;
		cout << "4.An option to search for a location record." << endl;
		cout << "5.do you want to save the changes to the file ?" << endl ;
		cout << "6.exit." << endl << endl;



	}


	int main() {
		CDList R;

		ifstream file;
		file.open("betseleem.csv");

		if (!file.is_open()) {
			cout << "Error opening file!" << endl;
			return 1;
		}

		
	

	
		string st;
		
		while (!file.eof()) {

			Martyr m;
			getline(file, st, ',');
			m.setname(st);
			getline(file, st, ',');
			m.setage(st);
			getline(file, st, ',');
			m.setloc(st);
			getline(file, st, ',');
			m.setDate(st);
			getline(file, st, '\n');
			m.setgender(st);

			R.add(m);



		}


		//R.nablus();

		//R.disl();
		// cout << endl;
	   //cout << R.size() << endl;
	  // R.d();
	   //cout << endl;
		//R.disvv();

		menu();
		


		while (1) {

			cout << "*** Choose any operation you need *** : ";
			int num;
			cin >> num;
			if (num == 1) {
				cout << "enter a new location wiht it's record   name , age , loc , date ,gender :  ";

				string a, b, c, d, e;
				cin >> a >> b >> c >> d >> e;
				R.insertNew(a, b, c, d, e);

				cout << "we added a new location record successfully ." << endl;

				//R.disl();


			}
			if (num == 2) {
				cout << "enter a location you need to replace it : "; string x; cin >> x;

				R.upDate(x);

				cout << "we update this location." << endl;
				//R.disl();


			}
			if (num == 3) {

				cout << "enter a location you need to delete it : "; string x; cin >> x;
				R.deleteLoc(x);
				cout << "we deleted this location " << endl;
				//R.disl();

			}
			if (num == 4) {
				cout << endl;
				cout << "a.Martyrs Menu " << endl << endl;
				cout << "b.Statistics Report" << endl << endl;

				cout << "choose a or b :";

				string x;
				cin >> x;
			
				if (x == "a") {

				



					cout << "1.Insert a new martyr record .\n2.Update a martyr record .\n3.Delete a martyr record .\n4.Search for a martyr by name and display his/her information ." << endl;
					cout << endl << "enter number of oberation : "; int a; cin >> a;

					if (a == 1) {
						cout << "Well, enter the city you want to edit : ";
						string h; getline(cin>>ws,h); R.insert2(h); }
					if (a == 2) {
						cout << "Well, enter the city you want to edit : ";
						string h; getline(cin>>ws,h);   R.upDate2(h);
					}
					if (a == 3) {
						cout << "Well, enter the city you want to edit : ";
						string h; getline(cin >> ws, h); R.deleteMar(h);
					}
					if (a == 4) {
						cout << "Well, enter the city you want to edit : ";
						string h; getline(cin >> ws, h); R.info(h); }










				}

				if (x == "b") {

					cout << "enter the name of city to dispaly the Statistics Report :  "; string v; cin >> v;

					R.statistics(v);



				}





			}


			if (num == 5) {




				cout << "Do you want to save the changes to the file ? " << endl;
				cout << "a. Yes ." << endl;
				cout << "b. No" << endl;
				string z; cin >> z;

				if (z == "b") { exit(0); }
				if (z == "a") {

					cout << "\nEnter folder path to save the file: "; string folder; cin >> folder;
					cout << "Enter file name to save the file (with .csv extension): ";
					string filename;
					cin >> filename;

					string filePath = folder + "//" + filename;
					R.saveToFile(filePath);
					
				}


			}



			if (num == 6) { exit(0); }
			if (!(num >= 1 && num <= 6));

		}
	}
