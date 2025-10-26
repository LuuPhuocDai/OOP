#include <iostream>
using namespace std;

// lop ma tran.
class matrix{
	private:
		int row;
		int col;
		int** data;
	public:
		// ham khoi tao.
		matrix(){
			row = 0;
			col = 0;
			
			data = new int*[row];
			// cap phat dong.
			for(int i = 0; i < row; i++){
				*(data + i) = new int[col];
			}
		}
		
		// getter
		int getCol(){
			return col;
		}
		int getRow(){
			return row;
		}
		int** getData(){
			return data;
		}
		
		// ham co tham so.
		matrix(int row, int col){
			this->row = row;
			this->col = col;
			
			data = new int* [row];
			// cap phat dong.
			for(int i = 0; i < row; i++){
				*(data + i) = new int[col];
			}
		}
		
		// ham sao chep.
		matrix(const matrix &p){
			row = p.row;
			col = p.col;
			
			data = new int* [p.row];
			// cap phat dong.
			for(int i = 0; i < row; i++){
				data[i] = new int[col];
			}
			for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                	data[i][j] = p.data[i][j];
                }
            }
		}
		
		// ham tao kich thuoc ma tran.
		void sizeMatrix(){
			cout<<"Nhap dong: "; cin >> row;
			cout<<"Nhap cot: "; cin >> col;
			
			data = new int* [row];
			// cap phat dong.
			for(int i = 0; i < row; i++){
				*(data + i) = new int[col];
			}
		}
		
		// ham nhap.
		void input(){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    cout<<"matrix[" << i + 1 <<"][" << j + 1 <<"] = ";
                    cin >> data[i][j];
                }
            }
		}
		
		// ham xuat ma tran.
		void outPut(){
			for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    cout<< data[i][j] <<"  ";
                }
                cout<< endl;
            }
		}
		
		// ham huy (giai phong bo nho).
		void deleteMatrix(){
			for(int i = 0; i < row; i++){
				delete[] data[i];
			}
			delete[] data;
		}
		
		// kiem tra ma tran vuong.
		bool square_matrix(){
			return row == col;
		}
		
		// kiem tra ma tran doi xung.
		bool symmetric_matrix(){
			if(!square_matrix()) return false;
			int count = 0;
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					if(data[i][j] == data[j][i]){
						count++;
					}
				}
			}
			if(count == row*col){
				return true;
			}
			else{
				return false;
			}
		}
		
		// tinh dinh thuc cua ma tran bang pp phan bu dai so.
		int determinant(int** data, int size){
			int det = 0, sign = 1;
			
			// dieu kien.
			if(size == 1){
				det = data[0][0];
			}
			else if(size == 2){
				det = data[0][0] * data[1][1] - data[0][1] * data[1][0];
			}
			else{
				for(int i = 0; i < size; i++){
					int** temp = new int*[size - 1];
                    for (int j = 0; j < size - 1; j++) {
                        temp[j] = new int[size - 1];
                    }
                    int sub_i = 0, sub_j = 0;
                    for (int j = 1; j < size; j++) {
                        for (int k = 0; k < size; k++) {
                            if (k == i) {
                                continue;
                            }
                            temp[sub_i][sub_j] = data[j][k];
                            sub_j++;
                        }
                        sub_i++;
                        sub_j = 0;
                    }

                    // tinh dinh thuc
                    det += sign * data[0][i] * determinant(temp, size - 1);
                    sign = -sign;
                    for (int j = 0; j < size - 1; j++) {
                        delete[] temp[j];
                    }
                    delete[] temp;
                }
            }
			return det;
		}
		
		// xuat ma tran bang operator.
		friend istream& operator >>(istream& CIN, matrix& a){
			a.sizeMatrix();
			cout<<"\nNhap gia tri: "<< endl;
			a.input();
			return CIN;
		}
		
		// nhap ma tran.
		friend ostream& operator <<(ostream& COUT, matrix& a){
			a.outPut();
			return COUT;
		}
		
		// phep cong hai ma tran cung kich thuoc.
		friend matrix operator +(const matrix& a, const matrix& b){
			matrix c;
			c.row = a.row;
			c.col = a.col;
			c.data = new int*[c.row];
			for(int i = 0; i < c.row; i++){
				c.data[i] = new int[c.col];
				for(int j = 0; j < c.col; j++){
					c.data[i][j] = a.data[i][j] + b.data[i][j];
				}
			}
			return c;
		}
		
		// phep tru hai ma tran cung kich thuoc.
		friend matrix operator -(const matrix& a, const matrix& b){
			matrix c;
			c.row = a.row;
			c.col = a.col;
			c.data = new int*[c.row];
			for(int i = 0; i < c.row; i++){
				c.data[i] = new int[c.col];
				for(int j = 0; j < c.col; j++){
					c.data[i][j] = a.data[i][j] - b.data[i][j];
				}
			}
			return c;
		}
		
		// phep nhan hai ma tran.
		friend matrix operator *(const matrix& a, const matrix& b){
			matrix c;
			c.row = a.row;
			c.col = b.col;
			c.data = new int*[c.row];
			for(int i = 0; i < c.row; i++){
				c.data[i] = new int[c.col];
				for(int j = 0; j < c.col; j++){
					c.data[i][j] = 0;
					for(int k = 0; k < a.col; k++){
						c.data[i][j] += a.data[i][k] * b.data[k][j];
					}
				}
			}
			return c; 
		}
		
		// so sanh hai ma tran.
		friend bool operator ==(const matrix& a, const matrix& b){
			int count = 0;
			if(a.row == b.row && a.col == b.col){
				for(int i = 0; i < a.row; i++){
				    for(int j = 0; j < a.col; j++){
					    if(a.data[i][j] == b.data[i][j]){
					    	count++;
					    }
				    }
			    }
			}
			else{
				return false;
			}
			
			if(count == a.row*a.col) return true;
			else return false;
		}
		
		// sao chep.
		matrix& operator =(const matrix& p){
			if (this == &p) return *this; 
    
            for (int i = 0; i < row; i++) {
                delete[] data[i];
            }
            delete[] data;

            row = p.row;
            col = p.col;
            data = new int*[row];
            for (int i = 0; i < row; i++) {
                data[i] = new int[col];
                for (int j = 0; j < col; j++) {
                    data[i][j] = p.data[i][j];
                }
            }
            return *this;
		}
};

// chuong trinh chinh.
int main(){
	matrix a, b;
	
	// nhap gia tri cua ma tran a.
	cout<<"Ma tran A: "<< endl;
	cin >> a;
	
	// xuat ma tran a.
	cout<<"\nXuat ma tran A: "<< endl;
	cout<< a;
	
	// kiem tra ma tran vuong.
	if(a.square_matrix()) cout<<"\nLa ma tran vuong cap "<< a.getCol() << endl;
	else cout<<"\nKhong phai la ma tran vuong"<< endl;
	
	// kiem tra ma tran doi xung.
	if(a.symmetric_matrix()) cout<<"\nLa ma tran doi xung."<< endl;
	else cout<<"\nKhong phai la ma tran doi xung."<< endl;
	
	// tinh dinh thuc ma tran.
	if(a.square_matrix()){
		cout<<"\nDeterminant cua ma tran vuong cap "<< a.getCol() << " la "<< a.determinant(a.getData(), a.getCol()) << endl;
	}
	else{
		cout<<"\nKhong tinh duoc Determinant vi khong phai la ma tran vuong!!!"<< endl;
	}

    // phep tinh giua hai ma tran.
    cout<<"\nCac toan tu:"<< endl;
    
	// nhap gia tri cua ma tran b.
	cout<<"\nMa tran b: "<< endl;
	cin >> b;
	
	// xuat ma tran b.
	cout<<"\nXuat ma tran b: "<< endl;
	cout<< b;
	
	// phep cong hai ma tran cung cap.
	if(a.getRow() == b.getRow() && a.getCol() == b.getCol()){
		matrix Tong = a + b;
		cout<<"\nTong hai ma tran a va b bang: "<< endl;
		cout<< Tong;
	}
	else{
		cout<<"\nKhong tinh duoc vi hai ma tran khong cung cap!!!"<< endl;
	}
	
	// phep tru hai ma tran cung cap.
	if(a.getRow() == b.getRow() && a.getCol() == b.getCol()){
		matrix hieu = a - b;
		cout<<"\nHieu hai ma tran a va b bang: "<< endl;
		cout<< hieu;
	}
	else{
		cout<<"\nKhong tinh duoc vi hai ma tran khong cung cap!!!"<< endl;
	}
	
	// nhan hai ma tran.
	if(a.getRow() == b.getCol()){// dieu kien.
		matrix tich = a * b;
		cout<<"\nTich hai ma tran a va b bang: "<< endl;
		cout<< tich;
	}
	else{
		cout<<"\nKhong tinh duoc vi khong thoa man dieu kien phep nhan"<< endl;
	}
	
	
	// so sanh hai ma tran.
	if(a == b) cout<<"\nHai ma tran bang nhau"<< endl;
	else cout<<"\nHai ma tran khong bang nhau"<< endl;
	
	// sao chep ma tran a bo vao c.
	cout<<"\nSao chep ma tran. C->A: "<< endl;
	matrix c = a;
	cout<<"Xuat ma tran C:"<< endl;
	cout<< c;
	
	// giai phong bo nho.
	a.deleteMatrix();
	b.deleteMatrix();
	
	return 0;
}