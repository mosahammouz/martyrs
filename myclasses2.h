#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Martyr {

private:
	string name;
	string age;
	string loc;
	string DateOfDeath;
	string gender;
	friend class CDList;
	friend class DNode;
public:
	string getname() { return name; }
	string getloc() { return loc; }
	string getDate() { return DateOfDeath; }
	string getgender() { return gender; }
	string getage() { return age; }


	void setname(string b) { name = b; }
	void setloc(string b) { loc = b; }
	void setDate(string b) { DateOfDeath = b; }
	void setgender(string b) { gender = b; }
	void setage(string b) { age = b; }




};

template<typename T>
class myVector {

private: T* arr;

	   int nvec;
	   int maxc;
	   friend class CDList;
	   friend class DNode;

public:
	myVector(int mc = 1000) {

		nvec = 0;
		maxc = mc;

		arr = new Martyr[maxc];



	}

	~myVector() {

		if (arr != NULL)delete[]arr;
		arr = NULL;

	}


	void setVector(Martyr& obj) {

		if (nvec == 0) {

			arr[nvec++] = obj;
			return;


		}

		if (nvec == 1) {}

		for (int i = 0; i < nvec; i++) {

			if (arr[i].getname() >= obj.getname()) {
				int j = i;

				int k = nvec;

				for (int l = k; k != j; k--) {

					arr[k] = arr[k - 1];




				}

				arr[j] = obj;
				nvec++;
				return;




			}


		}



		arr[nvec++] = obj;



	}

	int size() { return nvec; }


	void show() {

		for (int i = 0; i < nvec; i++) {

			cout << arr[i].getname() << endl;

		}

	}



	void disvec() {

		for (int i = 0; i < nvec; i++) {

			cout << arr[i].getname() << endl;





		}


	}




};


template<typename T>
class myStack {

private:
	T* arr;
	int t;
	int maxc;

	friend class CDList;
	friend class DNode;


public:
	myStack(int mc = 1000) {
		t = -1;
		maxc = mc;
		arr = new Martyr[maxc];



	}
	~myStack() {

		if (arr != NULL)delete[]arr;
		arr = NULL;

	}

	void push(Martyr& obj2) {

		if (t > maxc)return;

		t = t + 1;
		arr[t] = obj2;


	}

	string top() {


		//if (t == -1)exit(0);

		//return arr[t--].getDate();





	}

	int sizeStack() { return t; }
	//string getdate(int i) { return arr[i].getDate(); }


	void display() {
		for (int i = 0; i <= t; i++) {
			cout << arr[i].getname() << "\t";
			cout << arr[i].getage() << "\t";
			cout << arr[i].getloc() << "\t";
			cout << arr[i].getDate() << "\t";
			cout << arr[i].getgender() << "\t";
			cout << endl << endl;
		}



	}



	void min() {
		string min = "5/12/2001";
		for (int i = 0; i <= t; i++) {

			if (arr[i].getDate() < min) { min = arr[i].getDate(); cout << min << endl; return; }



		}



	}



};



class DNode {

private:
	string location;
	DNode* prev;
	DNode* next;

	myVector<Martyr> v;
	myStack<Martyr> s;

	friend class CDList;
	template<typename T>
	friend myStack;
	template<typename T>
	friend myVector;

public:



	DNode() { next = NULL; prev = NULL; }

	void sets(Martyr& obj) {

		s.push(obj);


	}

	//string getsn() { s.top(); }

	void setV(Martyr& obj3) { v.setVector(obj3); };





};



class CDList {

private:
	DNode* Head;
	int n;



public:

	CDList() {

		Head = NULL;
		n = 0;

	}

	bool embty()const { return Head == NULL; }
	int size()const { return n; }


	DNode* createNode() {

		DNode* N = new DNode;

		return N;



	}


	void add(Martyr& obj) {

		DNode* ptr = createNode();

		ptr->location = obj.loc;

		insertInOrder(ptr, obj);





	}


	void insertInOrder(DNode* p, Martyr u) {


		if (embty()) {

			Head = p;
			p->next = p;
			p->prev = p;
			n++;
			p->sets(u);
			p->setV(u);
			return;
		}

		if (n == 1) {

			if (Head->location == p->location) {

				Head->sets(u);
				Head->setV(u);
				return;

			}

			if (Head->location < (p->location)) {

				p->prev = Head;
				p->next = Head;




				Head->next = p;
				Head->prev = p;
				n++;
				p->sets(u);
				p->setV(u);
				return;

			}


			if (Head->location > (p->location)) {

				p->next = Head;
				p->prev = Head;

				Head->next = p;
				Head->prev = p;
				n++;

				Head = Head->prev;

				p->sets(u);
				p->setV(u);
				return;


			}



		}



		if (Head->location > (p->location)) {


			p->next = Head;
			p->prev = Head->prev;
			Head->prev->next = p;
			Head->prev = p;

			Head = Head->prev;
			n++;

			p->sets(u);
			p->setV(u);
			return;
		}

		if (Head->prev->location < (p->location)) {


			p->prev = Head->prev;
			p->next = Head;
			Head->prev->next = p;
			Head->prev = p;

			n++;
			p->sets(u);
			p->setV(u);
			return;

		}


		if (Head->prev->location == p->location) {

			Head->prev->sets(u);
			Head->prev->setV(u);
			return;


		}

		if (Head->location == p->location) {

			Head->sets(u);
			Head->setV(u);
			return;


		}

		DNode* cur = Head; DNode* past = NULL;

		do {

			past = cur;

			cur = cur->next;
			if (cur->location == p->location) {

				cur->sets(u);
				cur->setV(u);
				return;
			}




		} while (!(cur->location > (p->location)));


		p->next = cur;
		p->prev = past;
		cur->prev = p;
		past->next = p;




		n++;
		p->sets(u);
		p->setV(u);
		return;


	}


	void insertNew(string a, string b, string c, string d, string e) {

		Martyr m;
		m.setname(a);
		m.setage(b);
		m.setloc(c);
		m.setDate(d);
		m.setgender(e);

		DNode* ptr = createNode();
		ptr->location = c;
		insertInOrder(ptr, m);




	}


	void upDate(string a) {


		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == a) {
				cout << "enter the new location : "; string x; cin >> x;

				m->location = x;

				cout << endl;
				return;

			}

			m = m->next;


		}

		cout << "the location you entered does not exist ." << endl;


	}


	void deleteLoc(string a) {

		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == a) {

				if (m == Head) {

					Head = Head->next;
					m->prev->next = m->prev->next->next;
					m->prev = m->prev->prev;
					m->next = NULL;
					m->prev = NULL;
					delete m;
					return;

				}

				if (m == Head->prev) {

					Head->prev->prev->next = Head;
					Head->prev = Head->prev->prev;
					m->next = NULL;
					m->prev = NULL;
					delete m;
					return;



				}

				m->prev->next = m->next;
				m->next->prev = m->prev;
				m->next = NULL;
				m->prev = NULL;
				delete m;
				return;


			}

			m = m->next;


		}

		cout << "the location you entered does not exist ." << endl;





	}



	void insert2(string j) {


		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == j) {


				string a, b, c, d, e;
				cout << "enter name , age , loc ,Date Of Death , Gender respectively : ";

				cin >> a >> b >> c >> d >> e;
				/*getline(cin, a);
				getline(cin , b);
				getline(cin , c);
				getline(cin , d);
				getline(cin , e);*/
				Martyr l;
				l.setname(a);
				l.setage(b);
				l.setloc(c);
				l.setDate(d);
				l.setgender(e);

				m->sets(l);
				m->setV(l);
				insertInOrder(m, l);

				cout << " Done !" << endl;
				return;

			}

			m = m->next;


		}

		cout << "the location you entered does not exist ." << endl;








	}




	void upDate2(string j) {

		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == j) {

				cout << "enter name of Martyr to edit : "; 	string f;
				getline(cin>>ws , f);
				



				int y = m->s.sizeStack();

				for (int k = 0; k < y; k++) {

					if (f == m->s.arr[k].getname()) {


						string a, b, c, d, e;
						cout << "enter name , age , loc ,Date Of Death , Gender respectively : ";

						cin >> a >> b >> c >> d >> e;
						/*getline(cin >> ws, a);
						getline(cin >> ws, b);
						getline(cin >> ws, c);
						getline(cin >> ws, d);
						getline(cin >> ws, e);*/
						
						Martyr l;

						m->s.arr[k].setname(a);
						m->s.arr[k].setage(b);
						m->s.arr[k].setloc(c);
						m->s.arr[k].setDate(d);
						m->s.arr[k].setgender(e);

						m->v.arr[k].setname(a);
						m->v.arr[k].setage(b);
						m->v.arr[k].setloc(c);
						m->v.arr[k].setDate(d);
						m->v.arr[k].setgender(e);


						//m->v.disvec();

						cout << " Done !" << endl;
						return;



					}
				}

				//m->v.disvec();
				
				cout << "this martyr does not exist . " << endl;
				return;







			}

			m = m->next;


		}
		
		cout << "the location you entered does not exist ." << endl;










	}







	void deleteMar(string h2) {

		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == h2) {

				cout << "enter name of martyr you want to delete : "; string h; getline(cin >> ws, h);
				for (int k = 0; k < m->s.sizeStack(); k++) {

					if (h == m->s.arr[k].getname()) {


						m->s.arr[k].setname("NULL");
						m->s.arr[k].setage("NULL");
						m->s.arr[k].setloc("NULL");
						m->s.arr[k].setDate("NULL");
						m->s.arr[k].setgender("NULL");

						m->v.arr[k].setname("NULL");
						m->v.arr[k].setage("NULL");
						m->v.arr[k].setloc("NULL");
						m->v.arr[k].setDate("NULL");
						m->v.arr[k].setgender("NULL");
						//m->v.disvec();

						cout << "Done!" << endl;

						return;



					}



				}

				//m->v.disvec();
				cout << " this martyr does not exist !" << endl;
				return;

			}

			m = m->next;


		}

		cout << "the location you entered does not exist ." << endl;











	}




	void info(string g) {

		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == g) {
				cout << "enter name of martyr : "; string x; getline(cin >> ws, x);
			
				
				for (int k = 0; k < m->s.sizeStack()+1; k++) {


					if (x == m->s.arr[k].getname()) {

						cout << m->s.arr[k].getname() << endl;
						cout << m->s.arr[k].getage() << endl;
						cout << m->s.arr[k].getloc() << endl;
						cout << m->s.arr[k].getDate() << endl;
						cout << m->s.arr[k].getgender() << endl;

						return;

					}




				}

				cout << "this martyr does not exist !" << endl;
				return;

			}

			m = m->next;


		}

		cout << "the location you entered does not exist ." << endl;








	}




	void statistics(string x) {




		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == x) {


				cout << "'" << "The numbers of martyrs in the selected location is : ";

				cout << m->s.sizeStack() << "'" << endl << endl;

				m->s.display();

				m->s.min();

				return;

			}

			m = m->next;


		}

		cout << "the location you entered does not exist ." << endl;















	}




	void disl() {
		DNode* m = Head->prev;

		for (int i = 0; i < n; i++) {

			cout << m->location << endl;

			m = m->next;


		}


	}

	void d() {

		//cout<<	Head->next->s.sizeStack();
		Head->s.display();
	}


	void disvv() {

		Head->v.disvec();


	}
	void saveToFile(const string& filepath) {

		ofstream outFile(filepath);

		if (!outFile.is_open()) {
			cout << "Error opening file for writing: " << filepath << endl;
			return;




		}
		DNode* m = Head;

		do {


			for (int k = 0; k < m->v.size(); k++) {
				outFile << m->v.arr[k].getname() << ",";
				outFile << m->v.arr[k].getage() << ",";
				outFile << m->v.arr[k].getloc() << ",";
				outFile << m->v.arr[k].getDate() << ",";
				outFile << m->v.arr[k].getgender() << "\n";



			}
			m = m->next;
		} while (m != Head);






		outFile.close();
		cout << "Data has been successfully saved to " << filepath << endl;
	}


	void nablus() {

		DNode* m = Head;

		for (int i = 0; i < n; i++) {

			if (m->location == "Nablus") {

				for (int i = 0; i < m->v.size(); i++)
				{
					cout << m->v.arr[i].getname() << endl;



				}
		
				return;

			}

			m = m->next;


		}

		cout << "the location you entered does not exist ." << endl;







	}
};

