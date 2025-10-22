#include <iostream>
using namespace std;

// lop co so preson.
class person{
	private:
		char* name;
		int age;
		string gender;
	public:
		// ham khoi tao.git git
		person(){
			name = NULL;
			age = 0;
		}
		
		// ham chuyen tham so.
		person(char* name1, int age1, string gender1){
			name = name1;
			age = age1;
			gender = gender1;
		}
		
		// ham xuat thong tin.
		void outPut1(){
			cout<<"Ho va Ten: "<< name << endl;
			cout<< "Tuoi tac: "<< age << endl;
			cout<<"Gioi Tinh: "<< gender << endl;
		}
};

// lop dan xuat employeel.
class employeel : public person{
	private:
		long long employeeID;// id.
        char* position;// chuc vu.
        int salary; // luong.
    public:
    	// ham khoi tao.
    	employeel(){
    		employeeID = 0;
    		position = NULL;
    		salary = 0;
		}
		
		// chuyen tham so.
		employeel(char* name, int age, string gender, long long id, char* position1, int salary1) : person(name, age, gender){
			employeeID = id;
			position = position1;
			salary = salary1;
		}
		
		// ham hien thi thong tin.
		void outPut2(){
			person::outPut1();
			cout<<"Ma so: "<< employeeID << endl;
			cout<<"Chuc vu: "<< position << endl;
			cout<<"Muc luong: "<< salary << endl;
		}
};

// lop dan manager.
class manager : public employeel{
	private:
		char* department;// phong quan li.
	public:
		// ham khoi tao.
		manager(){
			department = NULL;
		}
		
		// chuyen tham so.
		manager(char* name, int age, string gender, long long id, char* position, int salary, char* department1) : employeel(name, age, gender, id, position, salary){
			department = department1;
		}
		
		// ham xuat thong tin.
		void outPut(){
			employeel::outPut2();
			cout<<"Phong quan li: "<< department << endl;
		}
};
		

// chuong trinh chinh.
int main(){
	
	cout<<"\n--- thong tin cua quan li ---\n";
	manager a = manager("Chau Van Cuu", 32, "nam", 121213, "Sep", 40000000, "Van Phong Quan Li Thong Tin");
	a.outPut();
	cout<<"--- --------------------- ---\n";
	
	cout<<"\n--- thong tin cua nhan vien 1 ---\n";
	manager b = manager("Chau Van De", 22, "nam", 121314, "Nhan Vien", 9000000, "Van Phong Quan Li Thong Tin");
	b.outPut();
	cout<<"--- --------------------- ---\n";
	
	cout<<"\n--- thong tin cua nhan vien 2 ---\n";
	manager c = manager("Chau Van Bo", 25, "nam", 121515, "Nhan Vien", 12000000, "Van Phong Quan Li Thong Tin");
	c.outPut();
	cout<<"--- --------------------- ---\n";
	return 0;
}
